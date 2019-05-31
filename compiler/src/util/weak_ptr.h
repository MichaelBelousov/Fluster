#ifndef FLUSTER_COMPILER_UTIL_WEAK_PTR_H
#define FLUSTER_COMPILER_UTIL_WEAK_PTR_H

#include <memory>

namespace fluster { namespace util {



template <typename T>
struct WeakPtr : std::weak_ptr<T>
{
private:
    struct SpecialConstructorTag {};
    // NOTE: SpecialConstructorTag will be optimized out by the compiler since it
    // is an unused empty argument, this allows us to use overload resolution
    // to choose between constructing an underlying object and returning a pointer
    // or constructing a smart pointer directly
    template<typename ...Args>
    WeakPtr(SpecialConstructorTag _, Args&& ...args)
        : std::weak_ptr<T>(
            std::make_shared<T>(
                std::forward<Args>(args)...))
    {}

public:
    template<typename ...Args>
    WeakPtr(Args&& ...args)
        : std::weak_ptr<T>(
            std::forward<Args>(args)...)
    {}

    template<typename ...Args>
    static
    Ptr<T>
    make(Args&& ...args)
    {
        return WeakPtr(SpecialConstructorTag(), std::forward<Args>(args)...);
    }
};



} }

#endif //FLUSTER_COMPILER_UTIL_WEAK_PTR_H
