
<!--- TODO: separate compiler, official std libs, docs into repositories -->

## C++

### Style

* use struct declarations for most types and put the public interface up front

```Cpp
struct A : public B
{
    //// Methods
    void f();

    int x;

    //// Construction
    A();

private:
    double d;

    //// Construction
    A(int in_x, double in_d);
};
```

* avoid underscored names, use in\_\* for constructor parameters

```
struct A
{
    A(int in_n);
}

A::A(int in_n)
    : n(in_n)
{}
```

* declare file namespace on the same line without any indentation impact on the file, and separate from the file contents by 3 lines


```Cpp
namespace outer { namespace inner { namespace deeper {



struct Content {};



} } }  //namespace outer::inner::deeper
```

* you can put a comment after only two lines after the namespace declaration

```Cpp
namespace space {


// comment

struct Content {};



}
```

* declare common object sections using a 4-slash comment

```Cpp
struct A
{
    //// Types
    using Ptr = util::Ptr<A>;
    //// Construction
    A()
    static int staticConstructorInitializerFunction()
    //// [Public|Private] Methods
    //// [Public|Private] Members
    //// [Public|Private] Interface
    ... Methods + members
    //// Operators
    //// Constants
    //// Overidden Methods
    //// Static Functions
};
```

* in large headers, use a separate implementation file for inlined (i.e. template) code, which you include after the file namespace end and call it "name.tpp" where name is the extension-free name of the header

```Cpp
} }  //namespace outer::inner

#include "a.tpp"

#endif //FILE_PATH_H
```

* commented out code (which you should avoid, prefer committing a deletion), has no space before it. English comments have a space, end of line English comments are two spaces from the end of the line of code and have no space after the comment delimiter.

```Cpp
// an english comment
//int code_comment = 5;
auto code = static_cast<int>(5);  //the always-auto idiom
```


Copy a similar file for the minutiae of this codebase's style, these are just
less obvious rules for general development.
