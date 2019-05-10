
# Everything interesting you can do in one file

```Fluster

struct B

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
comp heap<F: FuncCall<..As, R = _ReturnType>>  //template arg types by default is Type
    //something with arenas
    addr = cstdlib.malloc(sizeof(R))
    slot: !&R =
        mem.access<sizeof(R)>(addr): R
    slot = F(..As)
    return ptr<R>(addr)
    

//can one implement stackless coroutines with composers?
    
@async.stackless
func mystackless(): void
    url = api.routes.login
    @async.await(() => blockingLogin(url))

```
