#ifndef FLUSTER_COMPILER_UTIL_PTR_H
#define FLUSTER_COMPILER_UTIL_PTR_H

#include <type_traits> //enable_if
#include <memory>

namespace fluster { namespace util {



template <typename T>
struct Ptr : std::shared_ptr<T>
{
private:
    struct SpecialConstructorTag {};  //dummy type for SFINAEing hidden constructor

    template< typename _ = void
            , typename = std::enable_if_t<std::is_same<_,SpecialConstructorTag>::value>
            , typename ...Args
            >
    Ptr(Args&& ...args)
        : std::shared_ptr<T>(
            std::forward<Args>(args)...)
    {}

public:
    template< typename _ = void
            , typename = std::enable_if_t<!std::is_same<_,SpecialConstructorTag>::value>
            , typename ...Args
            >
    Ptr(Args&& ...args)
        : std::shared_ptr<T>(
            std::make_shared<T>(
                std::forward<Args>(args)...))
    {}

    //// Methods

    static
    Ptr<T>
    null();

    template<typename U>
    Ptr<U>
    castUp()
    {
        return std::static_pointer_cast<U>(*this);
    }

    template<typename U>
    Ptr<U>
    castDown()
    {
        return std::dynamic_pointer_cast<U>(*this);
    }

    template<typename ...Args>
    static
    Ptr<T>
    copy(Args&& ...args)
    {
        return Ptr<SpecialConstructorTag>(args...);
    }
};

template<typename T>
inline
Ptr<T>
Ptr<T>::
null()
{
    return std::make_shared<T>();
}



} }

#include "weak_ptr.h"

#include <string>
#include <iostream>

int main()
{
    std::string str("hello");
    fluster::util::Ptr<std::string> pstr(str);
    //auto cpstr = fluster::util::Ptr<std::string>::copy(pstr(str));
    std::cout << pstr.use_count() << std::endl;
}

#endif //FLUSTER_COMPILER_UTIL_PTR_H
