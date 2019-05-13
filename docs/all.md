
# Everything interesting you can do in one file

### Structs

```Fluster
struct A  //empty type

struct B
    a  //member type inferred from constructor invocations

b = B(4)
//b: B = {a="hello"}  //if uncommented, will fail on ambiguity

struct C
    a: i32

struct D
    a: f32
    b: Str

struct Node<T>
    val: !T
    next: &!Node<T>

// structs cannot be subtypes and must use composition
// instead of inheritance
struct E
    has D

assert(() => E subtypeof D)  //will fail

// rename embedded D instance and its member
struct F
    has D as d  //allows access to embedded D using name d
    has D.a as b  //allows access to D.a with F.b
    @priv has D as e //second embedded D, privately, with different name

// constructors
struct Point2D
    x
    y
    op init(this, in_x, in_y)
        this.x = in_x
        this.y = in_y

//members are public by default
struct
    @priv a
    priv
        b: [3]byte
        c: f64

// methods, static variables, static functions
struct Log
    /* A log for logging */
    name: Path
    @static
    log_dir: !Path

    func open_log_file()
        with fs.open(append=true, overwrite=true) as f
            return f
        handle FileDoesntExist
            fs.create(fs.join(log_dir, '#<name>.log'))
            retry
        
    meth log(this,
             format: CFormatStr,
             prefix: CFormatStr = 'Log Entry: ',
             ..args): void
        with fs.append(Path.join(Log.log_dir,this.path)) as file
            entry = cformat(prefix+format, ..args)
            file.write(entry)
    func change_path


```

### Functions

```Fluster

```

### Classes and Inheritance

```Fluster

//scope-based-destruction
struct B
    start
    op init(this)
        this.start = time.now()
    op del(this)
        now = time.now()
        interval = now - this.start
        stdout.write(interval.toStr())


params<ContainerType: Container<T: Type>>
class A \ is B
    public
        y
    private
        x
    @pub q: T

c = 5
f: Func<..> = (a:!,b) => ++a; a+b+c  //;
d = 10
ref_d: !& = d
g: Func<..> = (a:!,b) => ref_d=10, c+a+b

t: Tuple = (1,'world',4.2f)

a: Array<..> = [1,2,3]  //<..> is implicit?

a: List = [1,2,3] //initialize from array

what is a pack?

@kill_on_fail
func delete(p: !*!Ptr<..>) = 
    
bile = @casing.Pascal
       import('bile')
a, b = ..import('yum')

long = '''hello
world
this is my long string'''

dedented = \`\`\`
           hello
           world
           this is my long dedented and trimmed string
           \`\`\`

x:! = 100
atcomp
    x = math.log(x)

    
lastly:

blah: Str = 
    case x is
        0 then
            "zero"
        1 then
            "one"
        _ then
            "other"

for s in "hello"[0..3]
    print(s)
//h,e,l,l


regex = /hel.*?world/gm

//pointer?
ptr: *m = #regex;

//A reference to an optional size-3 array of mutable pointers to 32-bit integers
MyType = &?[3]!*i32;

/* error handling */
    
//mandated exception handling

openfile('path.ext')

case File.open('dir/path.ext')
    as f ->
        
    ExistsException as e ->
        File.delete('dir/path.ext')
        retry


//watch File.create...
//prepare File.create...

f = File.create('dir/path.ext')
handle File.AlreadyExists, File.Wait as e
    File.delete('dir/path.ext')
    retry

//no try, just catch
//no silent failure, treat exceptions like types,
//they must be explicitly and exhaustively handled!
    
    
int_set = {1,2,3}
empty_set = {}  // deferred static type assertion
int_set == empty_set //asserts type of empty_set to be Set<i32>

anon_struct_val = {
    world = "hello",
    magic = 56
}

AnonStructType = {
    world: Str,
    magic: u32
}

//heap allocation
x = @heap String('hello')

//use a reference, raw memory access, and return value
//in-place construction to allocate an object on the heap
comp heap<F: FuncCall<Func<..As, R = _ReturnType>>>  //template arg types by default is Type
    //something with arenas
    addr = cstdlib.malloc(sizeof(R))
    slot: !&R =
        mem.access<sizeof(R)>(addr): R
    slot = F(..As)
    return slot: &R
    

//can one implement stackless coroutines with composers?
    
@async.stackless
func mystackless(): void
    url = api.routes.login
    @async.await(() => blockingLogin(url))

namespace async
    cur_threads
    thread_table = [MAX_THREADS]!&Thread

    struct FrozenStacklessCoroutine<F>
        program_counter: i32
        frame: F._Frame
        
    comp stackless<F: Func<..>>
        frozen: !FrozenStacklessCoroutine<F>
        meth restore(): void
            //_stack.current_frame = frozen.frame
            _stack = frozen.frame
            _program_counter = frozen.program_counter
        meth freeze(): void
            frozen.program_counter = _program_counter
            frozen.frame = _stack[-F._Frame.size..]
        return F

    struct FrozenStackfullCoroutine<frame: StackFrame>
        program_counter: i32

    priv
        switchContext()
            ...

```

### Simultaneous algorithms

the instructions of the first iteration are interleaved.

```Fluster
namespace Svg

    default_version = 1.1

    class Value

    enum Errors
        InvalidSyntax

    func validate(input: Stream<Char>): Bool
        ...
    func unsafe_parse(input: Stream<Char>, version=default_version): Value
        ...

    func parse(input: Stream<Char>, version=default_version): Value
        run validate as valid,
        run parse(input, version) as parse_result  //custom arguments including iterator
        over input
            if ~valid \ raise Errors.InvalidSyntax
        return parse_result
```
