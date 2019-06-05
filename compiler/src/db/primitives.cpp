#include "primitives.h"
#include "type.h"
#include "context.h"
#include <vector>
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

    /*
    Type::Ptr make_f32(GenerationContext ctx)
    {
        auto f32 = Type::Ptr::make();
        f32.db.addOperation(
            "add",
            Operation::Ptr::make(
                f32,
                {f32, f32},
                [](const std::vector<llvm::Value*>& args) {
                    return ctx.builder.CreateFAdd(args[0], args[1], "f32-add")
                }
            )
        );
        f32.db.addOperation(
            "sub",
            Operation::Ptr::make(
                f32,
                {f32, f32},
                [](const std::vector<llvm::Value*>& args) {
                    return ctx.builder.CreateFSub(args[0], args[1], "f32-sub")
                }
            )
        );
        f32.db.addOperation(
            "mul",
            Operation::Ptr::make(
                f32,
                {f32, f32},
                [](const std::vector<llvm::Value*>& args) {
                    return ctx.builder.CreateFMul(args[0], args[1], "f32-mul")
                }
            )
        );
        f32.db.addOperation(
            "lt",
            Operation::Ptr::make(
                f32,
                {f32, f32},
                [](const std::vector<llvm::Value*>& args) {
                    auto bool_result = CreateFCompULT(args[0], ars[1], "f32-lt");
                    return ctx.builder.CreateUIToFP(bool_result, Type::getDoubleTy(ctx));
                }
            )
        );
        return f32;
    }
    */
}


void commitPrimitives(ProgramDatabase& db, GenerationContext& ctx)
{
    // XXX: stub
    //db.addType(make_i32);
}

const Type::Ptr type_type = Type::Ptr::make(Name("Type"), true);

//integer primitive types
//const Type::Ptr i8(new Type);
//const Type::Ptr i16(new Type);
const Type::Ptr i32 = Type::Ptr::make(Name("i32"), true); // = make_i32(the_context);
//const Type::Ptr i64(new Type);
//const Type::Ptr Int(new Type);
//const Type::Ptr APInt(new Type);

//unsigned integer primitive types
//const Type::Ptr u8(new Type);
//const Type::Ptr u16(new Type);
//const Type::Ptr u32(new Type);
//const Type::Ptr u64(new Type);
//const Type::Ptr UInt(new Type);


//floating point primitive types
const Type::Ptr f32 = Type::Ptr::make(Name("f32"), true); //= make_f32(the_context);
//const Type::Ptr f64(new Type);
//const Type::Ptr Float(new Type);
//const Type::Ptr APFloat(new Type);

//raw types
//const Type::Ptr Bit(new Type);
//const Type::Ptr Byte(new Type);
//const Type::Ptr Word(new Type);



} }  //namespace fluster::db
