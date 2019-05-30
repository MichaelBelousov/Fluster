#ifndef FLUSTER_COMPILER_AST_OPS_ADD
#define FLUSTER_COMPILER_AST_OPS_ADD

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Add final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    Add(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = std::shared_ptr<Add>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_ADD
