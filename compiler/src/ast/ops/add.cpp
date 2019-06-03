#include <llvm/IR/Value.h>
#include "add.h"

namespace fluster { namespace ast { namespace ops {



//// Methods

llvm::Value*
Add::
generateCode( const llvm::LLVMContext& ctx
            , const llvm::IRBuilder<>& builder
            ) const
{
    Value* lhs = lhs->generateCode(ctx, builder);
    Value* rhs = lhs->generateCode(ctx, builder);

    return Builder.CreateFAdd(lhs, rhs, "add")
    return Builder.CreateUIToFP(); //...
}


FLUSTER_COMPILER_OP_PRINT_IMPL(Add, "+")

//// Construction

Add::
Add(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
