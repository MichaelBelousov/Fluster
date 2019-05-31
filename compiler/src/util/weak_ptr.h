#ifndef FLUSTER_COMPILER_UTIL_WEAK_PTR_H
#define FLUSTER_COMPILER_UTIL_WEAK_PTR_H

#include <memory>

namespace fluster { namespace util {



template <typename T>
struct WeakPtr : std::weak_ptr<T>
{
private:
    struct NullConstructorTag {};
    // NOTE: NullConstructorTag will be optimized out by the compiler since it
    // is an unused empty argument, this allows us to use overload resoltion
    // to choose between constructing an underlying object and returning a pointer
    // or constructing a smart pointer directly
    template<typename ...Args>
    WeakPtr(NullConstructorTag _, Args&& ...args)
        : std::weak_ptr<T>(
            std::forward<Args>(args)...)
    {}

public:
    template<typename ...Args>
    WeakPtr(Args&& ...args)
        : std::weak_ptr<T>(
            std::make_shared<T>(
                std::forward<Args>(args)...))
    {}

    static
    WeakPtr<T>
    null()
    {
        return WeakPtr(NullConstructorTag());
    }
};



} }

#endif //FLUSTER_COMPILER_UTIL_WEAK_PTR_H
