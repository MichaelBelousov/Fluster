#ifndef FLUSTER_COMPILER_AST_OPS_INT_DIVIDE
#define FLUSTER_COMPILER_AST_OPS_INT_DIVIDE

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct IntDivide final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    IntDivide(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = std::shared_ptr<IntDivide>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_INT_DIVIDE
