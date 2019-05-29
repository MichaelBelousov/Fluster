#ifndef FLUSTER_COMPILER_AST_OPS_ROOT
#define FLUSTER_COMPILER_AST_OPS_ROOT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Root final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    Root( Expr::Ptr left
        , Expr::Ptr right
        );

    //// Types
    using Ptr = std::shared_ptr<Root>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_ROOT
