#ifndef FLUSTER_COMPILER_AST_OPS_ROOT
#define FLUSTER_COMPILER_AST_OPS_ROOT

#include "util/ptrs.h"
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Root final
    : public BinaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    Root( Expr::Ptr left
        , Expr::Ptr right
        );

    //// Types
    using Ptr = util::Ptr<Root>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_ROOT
