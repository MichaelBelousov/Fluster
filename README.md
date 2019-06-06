
# Fluster

A general programming language with an emphasis on simplicity, power, and interop.
Meant to provide too much power such that you never, *ever* repeat yourself.

## Introduction

Fluster code constructs can be made parametric
uniformly

```Fluster
interface Comparable
    op lt (lhs: &Comparable, rhs: &Comparable)

struct PriorityQueue
    < ContainerType: Container<T: Type>
    , priority: Func<R: Comparable, T>
    >
    private
        container: ContainerType
    mthd add(t: T): void
        i = container.length
        for (i,x) in index(container)
            if priority(x) > priority(t)
                continue
            else
                container.insert(t, i)
                return
            i--
```

```Fluster
List2D<T: Type> = List<List<T>>
mylist: List2D<char>
mylist = [['h', 'y'], ['n', 'n'], []]

BST<T> = Tuple<T, BST<T>|nil, BST<T>|nil>
// optional type syntax
BST<T> = Tuple<T, ?BST<T>, ?BST<T>>

mylist: List2D<char>
mylist = [['h', 'y'], ['n', 'n'], []]

// semicolon is like the C comma operator
shift = (in) => mylist.pop(); mylist.prepend(in)
```

Fluster code is strongly typed and heavily inferred.
Value idioms and constructs are used on types wherever appropriate
including operators.

```Fluster
val: int = 4            //typed declaration
MyFloat: Type = float64 //type alias
decimal = val: float64  //casting is the same syntax
```

Fluster code is expressive and readable with core data structure
literals, idiomatic byte literals, and more.

```Fluster
MyType = {foo: i64, bar: Dbl}
int_array: []int = 1, 5, 10, -4
val: [4]byte = 0x00fa43fc  //implicit conversion
val: [1]byte = 0b11010100  //implicit conversion
string_array = "foo", "bar"
string_list = ["foo", "bar"]
string_map: Map<String, u32>  = {foo = 40}  //constructor from static reflection
string_map = {"foo" = 40}

struct Person
    name: char[10]
    age: u8

dan = 0x6d696b6500000000000014: Person
```

Fluster has pack idioms

```Fluster
val2 = 0x5f            //inferred to [1]byte
val3, = 0x5f           //inferred to byte
x = 'hello'            //[5]char
y: String = 'hello'    //converted from char array to string of length 5

a, b, c, ...rest = [5, 6, -2, 20, 4]
a == 5
b == 6
c == -2
rest == [20, 4]

mylist: List2D<T> = (1, 2), (), (0,), (4, 5, 8, 2)
```


Fluster code has granular declarative composition
for easy code reuse


```Fluster
class A
    is B            // inheritance
    has C           // delegation
    has D as d      // delegation with accessible 
                    // object, d
    has E.g as g    // single function delegation
    has F.h as f.h  // single function delegation 
                    // with accessible object f
```


Fluster code supports every level of abstraction, with strong
code generation and static reflection, or runtime reflection
only when you need it.


```Fluster
comp flag_enum<target: Enum>
    for i, m in index(target._members)
        m._value = 2^i

@flag_enum
enum FileOpenFlags
    read
    write
    append

Flags.append == 0b00000100
Flags.read | Flags.write == 0b00000011


Str = String
comp require_user_pass
    < target: Func
    , log_msg: Str = "access fail by !{usr}"
    >
    func wrapper(usr: Str, psw: Password, ...args: Args)
        if authorize(usr, psw) 
            return target(...args)
        else 
            log.warn(fmt(log_msg, usr, ...args))
            return (forbidden_page, 403)
    target = wrapper

@require_user_pass<"bad auth by !{usr} when searching !{id}">
func search_user(id: String)
    pass
```

Fluster can even let you modify modules to add appropriate 
functions, transform others, or even ignore other people's 
demented casing choices.

```Fluster
aclass, b_class, cClass = import('gross.bile')
```

What gross inconsistency, we can patch that module
but we will need to fix at least the aclass declaration
ourselves which we can do with a custom composer


```Fluster
snake_caser, = import('casing')

comp bile_fix<target: Module>
    @snake_caser
    module wrapper
        merges target
        a_class = aclass
        delete aclass
        class d_class \ is a_class
    target = wrapper

a_class, b_class, c_class, d_class
    = @bile_fix import('gross.bile')

@bile_fix
import gross.bile
```
