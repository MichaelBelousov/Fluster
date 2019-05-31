#ifndef FLUSTER_COMPILER_AST_OPS_POSTINCREMENT
#define FLUSTER_COMPILER_AST_OPS_POSTINCREMENT

#include "util/ptrs.h"
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PostIncrement final
    : public UnaryOperator
{
    //// Methods

    //// Construction
    PostIncrement(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<PostIncrement>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_POSTINCREMENT
