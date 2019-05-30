#ifndef FLUSTER_COMPILER_UTIL_PTR_H
#define FLUSTER_COMPILER_UTIL_PTR_H

#include <memory>

namespace fluster { namespace util {


template <typename T>
struct WeakPtr : std::weak_ptr<T>
{

    template<typename ...Args>
    WeakPtr(Args&& ...args)
        : std::weak_ptr<T>(
            std::make_shared<T>(
                std::forward<Args>(args)...))
    {}

    static
    WeakPtr<T>
    null();

private:
    struct null_constructor_type_tag {};
    template<>
    WeakPtr<null_constructor_type_tag>()
        : std::weak_ptr<T>()
    {}
};

template<typename T>
inline
WeakPtr<T>
WeakPtr<T>::
null()
{
    return WeakPtr<null_constructor_type_tag>();
}

template <typename T>
struct Ptr : std::shared_ptr<T>
{
    template<typename ...Args>
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
    castUp()
    {
        return std::static_pointer_cast<U>(*this);
    }

    template<typename U>
    castDown()
    {
        return std::dynamic_pointer_cast<U>(*this);
    }

private:
    struct null_constructor_type_tag {};
    template<>
    Ptr<null_constructor_type_tag>()
        : std::shared_ptr<T>()
    {}

public:
    template<typename ...Args>
    static
    Ptr<T>
    copy(Args&& ...args)
    {
        return Ptr<null_constructor_type_tag>(...args);
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

#endif //FLUSTER_COMPILER_UTIL_PTR_H
