#ifndef FLUSTER_COMPILER_AST_OPS_PREDECREMENT
#define FLUSTER_COMPILER_AST_OPS_PREDECREMENT

#include "util/ptr.h"
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PreDecrement final
    : public UnaryOperator
{
    //// Methods

    //// Construction
    PreDecrement(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<PreDecrement>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_PREDECREMENT
