#ifndef FLUSTER_COMPILER_AST_OPS_ADD
#define FLUSTER_COMPILER_AST_OPS_ADD

#include "util/ptrs.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Add final
    : public BinaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    Add(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = util::Ptr<Add>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_ADD
