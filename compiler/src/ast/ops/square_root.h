#ifndef FLUSTER_COMPILER_AST_OPS_SQUAREROOT
#define FLUSTER_COMPILER_AST_OPS_SQUAREROOT

#include "util/ptrs.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct SquareRoot final
    : public UnaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    SquareRoot(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<SquareRoot>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_SQUAREROOT
