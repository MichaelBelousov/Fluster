#ifndef FLUSTER_COMPILER_UTIL_WEAK_PTR_H
#define FLUSTER_COMPILER_UTIL_WEAK_PTR_H

#include <type_traits> //enable_if
#include <memory>

namespace fluster { namespace util {


template <typename T>
struct WeakPtr : std::weak_ptr<T>
{
private:
    struct NullConstructorTag {};  //dummy type for SFINAEing hidden constructor

    template< typename U = void
            , std::enable_if_t<std::is_same<U,NullConstructorTag>::value>
            //, typename ...Args
            >
    WeakPtr(/*Args&& ...args*/)
        : std::weak_ptr<T>()
    {}

public:
    template< typename U = void
            , std::enable_if_t<!std::is_same<U,NullConstructorTag>::value>
            , typename ...Args
            >
    WeakPtr(Args&& ...args)
        : std::weak_ptr<T>(
            std::make_shared<T>(
                std::forward<Args>(args)...))
    {}

    static
    WeakPtr<T>
    null();
};



template<typename T>
inline
WeakPtr<T>
WeakPtr<T>::
null()
{
    return WeakPtr<NullConstructorTag>();
}



} }

#endif //FLUSTER_COMPILER_UTIL_WEAK_PTR_H
