#ifndef FLUSTER_COMPILER_AST_OPS_LAMBDA
#define FLUSTER_COMPILER_AST_OPS_LAMBDA

#include "util/ptrs.h"
#include "expr.h"
#include "comma_delimited_list.h"

namespace fluster { namespace ast {


// TODO: not really an operator, move out to some more specific folder

struct Lambda final
    : public Expr
{
    //// Methods
    llvm::Value* generateCode(GenerationContext& ctx) const final;

    //// Construction
    Lambda(CommaDelimitedList::Ptr in_args, Expr::Ptr in_body);

    //// Types
    using Ptr = util::Ptr<Lambda>;

    //// Members
    CommaDelimitedList::Ptr args;
    Expr::Ptr body;
};



} }

#endif //FLUSTER_COMPILER_AST_OPS_LAMBDA
