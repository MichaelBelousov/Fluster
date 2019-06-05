#include "primitives.h"

#include "type.h"
#include "context.h"
#include <vector>
#include <llvm/IR/Constants.h>
#include "name.h"

namespace fluster { namespace db {



/* Primitive types */

namespace
{
    /*
     * TODO: abstraction
    template <std::string& name, auto f>
    Type::Ptr make_primitive(GenerationContext& ctx)
    {
        auto result = Type::Ptr::make();
        result.db.addOperation(
            result,
            {result, result},
            [](const std::vector<llvm::Value*>& args) {
                return f(ctx)(args[0], args[1], "i32-add")
            }
        );

        return result;
    }

    Type::Ptr make_i32(GenerationContext& ctx) {
        static const char* add = "add";
        return make_primitive
            < add
            , [](Generation& ctx) {return ctx.builder.CreateFAdd}
            > (ctx);
    }
    */

    Type::Ptr make_f64(GenerationContext& ctx)
    {
        auto f64 = Type::Ptr::make(Name("f64"), true);
        // TODO: operations need to be qualified by name and signature
        ctx.db.addOperation(
            Name("add"),
            Operation::Ptr::make(
                Name("add"),
                f64,
                std::vector<Type::Ptr>({f64, f64}),
                [](GenerationContext& ctx, const std::vector<llvm::Value*>& args) -> llvm::Value* {
                    return ctx.builder.CreateFAdd(args[0], args[1], "f64-add");
                }
            )
        );
        ctx.db.addOperation(
            Name("sub"),
            Operation::Ptr::make(
                Name("sub"),
                f64,
                std::vector<Type::Ptr>({f64, f64}),
                [](GenerationContext& ctx, const std::vector<llvm::Value*>& args) -> llvm::Value* {
                    return ctx.builder.CreateFSub(args[0], args[1], "f64-sub");
                }
            )
        );
        ctx.db.addOperation(
            Name("mul"),
            Operation::Ptr::make(
                Name("mul"),
                f64,
                std::vector<Type::Ptr>({f64, f64}),
                [](GenerationContext& ctx, const std::vector<llvm::Value*>& args) -> llvm::Value* {
                    return ctx.builder.CreateFMul(args[0], args[1], "f64-mul");
                }
            )
        );
        ctx.db.addOperation(
            Name("lt"),
            Operation::Ptr::make(
                Name("lt"),
                f64,
                std::vector<Type::Ptr>({f64, f64}),
                [](GenerationContext& ctx, const std::vector<llvm::Value*>& args) -> llvm::Value* {
                    return ctx.builder.CreateFCmpULT(args[0], args[1], "f64-lt");
                }
            )
        );
        return f64;
    }
}


void commitPrimitives(GenerationContext& ctx)
{
    *const_cast<Type::Ptr*>(&f64) = make_f64(ctx);
    ctx.db.addType(Name("f64"), f64);
}

const Type::Ptr type_type = Type::Ptr::make(Name("Type"), true);

// integer primitive types
//const Type::Ptr i8(new Type);
//const Type::Ptr i16(new Type);
const Type::Ptr i32 = Type::Ptr::make(Name("i32"), true);
const Type::Ptr i64 = Type::Ptr::make(Name("i64"), true);
//const Type::Ptr Int(new Type);
//const Type::Ptr APInt(new Type);

// unsigned integer primitive types
//const Type::Ptr u8(new Type);
//const Type::Ptr u16(new Type);
//const Type::Ptr u32(new Type);
//const Type::Ptr u64(new Type);
//const Type::Ptr UInt(new Type);


// XXX: remove these globals and instead have them searched for from the context
// floating point primitive types
const Type::Ptr f32 = Type::Ptr::make(Name("f32"), true);
const Type::Ptr f64 = Type::Ptr::make(Name("f64"), true);
//const Type::Ptr Float(new Type);
//const Type::Ptr APFloat(new Type);

// raw memory types
//const Type::Ptr Bit(new Type);
//const Type::Ptr Byte(new Type);
//const Type::Ptr Word(new Type);



} }  //namespace fluster::db
