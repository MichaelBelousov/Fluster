#ifndef FLUSTER_COMPILER_AST_OPS_SQUAREROOT
#define FLUSTER_COMPILER_AST_OPS_SQUAREROOT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct SquareRoot final
    : public UnaryOperator
{
    //// Methods

    //// Construction
    SquareRoot(Expr::Ptr in_operand);

    //// Types
    using Ptr = std::shared_ptr<SquareRoot>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_SQUAREROOT
