#ifndef FLUSTER_COMPILER_AST_OPS_POST_DECREMENT
#define FLUSTER_COMPILER_AST_OPS_POST_DECREMENT

#include <memory>
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct PostDecrement final
    : public UnaryOperator
{
    //// Methods

    //// Construction
    PostDecrement(Expr::Ptr in_operand);

    //// Types
    using Ptr = std::shared_ptr<PostDecrement>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_POST_DECREMENT
