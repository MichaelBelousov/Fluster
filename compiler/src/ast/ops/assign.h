#ifndef FLUSTER_COMPILER_AST_OPS_ASSIGN
#define FLUSTER_COMPILER_AST_OPS_ASSIGN

#include "util/ptr.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Assign final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    Assign(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = util::Ptr<Assign>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_ASSIGN
