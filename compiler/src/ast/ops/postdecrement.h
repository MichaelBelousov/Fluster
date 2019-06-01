#ifndef FLUSTER_COMPILER_AST_OPS_POSTDECREMENT
#define FLUSTER_COMPILER_AST_OPS_POSTDECREMENT

#include "util/ptrs.h"
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PostDecrement final
    : public UnaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    PostDecrement(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<PostDecrement>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_POSTDECREMENT
