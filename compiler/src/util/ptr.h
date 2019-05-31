#ifndef FLUSTER_COMPILER_UTIL_PTR_H
#define FLUSTER_COMPILER_UTIL_PTR_H

#include <memory>

namespace fluster { namespace util {



template <typename T>
struct Ptr : std::shared_ptr<T>
{
private:
    struct SpecialConstructorTag {};
    // NOTE: NullConstructorTag will be optimized out by the compiler since it
    // is an unused empty argument, this allows us to use overload resoltion
    // to choose between constructing an underlying object and returning a pointer
    // or constructing a smart pointer directly
    template<typename ...Args>
    Ptr(SpecialConstructorTag _, Args&& ...args)
        : std::shared_ptr<T>(
            std::forward<Args>(args)...)
    {}

public:
    template<typename ...Args>
    Ptr(Args&& ...args)
        : std::shared_ptr<T>(
            std::make_shared<T>(
                std::forward<Args>(args)...))
    {}

    //// Methods
    static
    Ptr<T>
    null()
    {
        return Ptr(SpecialConstructorTag());
    }

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
        return Ptr(SpecialConstructorTag(),
                   std::forward<Args>(args)...);
    }
};



} }

#endif //FLUSTER_COMPILER_UTIL_PTR_H
