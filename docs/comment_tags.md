
# Why comment when you can code?

Instead of using comments, use the power and expressiveness of
composers to lend data to your comments, which can be used by
IDEs, VCS, etc.

```fluster
// TODO<mikeb>: write test cases!
func log2<T: is Natural>(n: T)
  if n < 2 \ return 1
  else \ return 1 + log2(n//2)
```

Alright, so that's readable, but you'd have to write your own scanner
for such comments, and because it is a comment, syntax errors would not
be found by your compiler, they would have passed easily, such as:

```fluster
// TODO<gab> write test cases!
func log2<T: is Natural>(n: T)
  if n < 2 \ return 1
  else \ return 1 + log2(n//2)
```

Instead, use an empty composer

```fluster
comp TODO<_target, assignee: Str>(..a)
  //maybe populate a compilation log here, or
  //update a database
  return _target

//...

@TODO<'gab'>('write test cases')
func log2<T: is Natural>(n: T)
  if n < 2 \ return 1
  else \ return 1 + log2(n//2)
```
