#ifndef FLUSTER_COMPILER_AST_OPS_PREINCREMENT
#define FLUSTER_COMPILER_AST_OPS_PREINCREMENT

#include "util/ptrs.h"
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PreIncrement final
    : public UnaryOperator
{
    //// Methods

    //// Construction
    PreIncrement(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<PreIncrement>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_PREINCREMENT
