
# Constructors

What will constructors look like?



a separate function?

```Fluster
class A()
    func create(in_x): A
        x = in_x
    x: i32
    y: i32
```

part of the class definition?

```Fluster
class A<T>(in_x: int)
    x = in_x
    y = 5
```

An operation?

```Fluster
class A()
    op construct(in_x): A
        x = in_x
    x: i32
    y: i32
```
