#ifndef FLUSTER_COMPILER_AST_OPS_DIVIDE
#define FLUSTER_COMPILER_AST_OPS_DIVIDE

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Divide final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    Divide(Expr::Ptr left, Expr::Ptr right);

    //// Types
    using Ptr = std::shared_ptr<Divide>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_DIVIDE
