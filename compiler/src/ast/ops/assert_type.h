#ifndef FLUSTER_COMPILER_AST_OPS_ASSERTTYPE
#define FLUSTER_COMPILER_AST_OPS_ASSERTTYPE

#include <memory>
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
    using Ptr = std::shared_ptr<AssertType>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_ASSERTTYPE
