#ifndef FLUSTER_COMPILER_UTIL_PTR_H
#define FLUSTER_COMPILER_UTIL_PTR_H

#include <memory>

namespace fluster { namespace util {



template <typename T>
struct Ptr : std::shared_ptr<T>
{
    //the cast functions in all instantiations have full access to
    //the other instantiations' members. This is necessary for construction
    template<typename U> template<typename V> friend Ptr<V> Ptr<U>::castUp();
    template<typename U> template<typename V> friend Ptr<V> Ptr<U>::castDown();

    //// Construction
private:
    struct SpecialConstructorTag {};
    // NOTE: SpecialConstructorTag will be optimized out by the compiler since it
    // is an unused empty argument, this allows us to use overload resolution
    // to choose between constructing an underlying object and returning a pointer
    // or constructing a smart pointer directly
#pragma GCC diagnostic ignored "-Wunused-parameter"
    template<typename ...Args>
    Ptr(SpecialConstructorTag _, Args&& ...args)
        : std::shared_ptr<T>(
            std::make_shared<T>(
                std::forward<Args>(args)...))
    {}
#pragma GCC diagnostic pop

public:
    template<typename ...Args>
    Ptr(Args&& ...args)
        : std::shared_ptr<T>(
            std::forward<Args>(args)...)
    {}

    //// Methods
    template<typename U>
    Ptr<U>
    castUp()
    {
        return Ptr<U>(std::static_pointer_cast<U>(*this));
    }

    template<typename U>
    Ptr<U>
    castDown()
    {
        return Ptr<U>(std::dynamic_pointer_cast<U>(*this));
    }

    template<typename ...Args>
    static
    Ptr<T>
    make(Args&& ...args)
    {
        return Ptr(SpecialConstructorTag(), std::forward<Args>(args)...);
    }
};



} }

/*
#include <iostream>

struct A {};
struct B: public A {};

int main()
{
    using namespace fluster::util;
    using namespace std;
    Ptr<A> pa;
    auto pb = Ptr<B>::make();
    Ptr<B> pb2;
    pa = pb;
    cout << pa.use_count() << endl;
    cout << pa << endl;
    cout << pb << endl;
    cout << pb2 << endl;
}
*/

#endif //FLUSTER_COMPILER_UTIL_PTR_H
