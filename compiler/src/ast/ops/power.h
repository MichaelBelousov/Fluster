#ifndef FLUSTER_COMPILER_AST_OPS_POWER
#define FLUSTER_COMPILER_AST_OPS_POWER

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Power final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    Power( Expr::Ptr left
         , Expr::Ptr right
         );

    //// Types
    using Ptr = std::shared_ptr<Power>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_POWER
