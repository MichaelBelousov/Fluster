#ifndef FLUSTER_COMPILER_AST_OPS_ASSERTTYPE
#define FLUSTER_COMPILER_AST_OPS_ASSERTTYPE

#include "util/ptrs.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct AssertType final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    AssertType(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = util::Ptr<AssertType>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_ASSERTTYPE
