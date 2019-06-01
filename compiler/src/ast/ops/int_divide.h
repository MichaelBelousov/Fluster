#ifndef FLUSTER_COMPILER_AST_OPS_INT_DIVIDE
#define FLUSTER_COMPILER_AST_OPS_INT_DIVIDE

#include "util/ptrs.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct IntDivide final
    : public BinaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    IntDivide(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = util::Ptr<IntDivide>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_INT_DIVIDE
