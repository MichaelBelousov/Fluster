#ifndef FLUSTER_COMPILER_AST_OPS_MULTIPLY
#define FLUSTER_COMPILER_AST_OPS_MULTIPLY

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Multiply final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    Multiply( Expr::Ptr left
            , Expr::Ptr right
            );

    //// Types
    using Ptr = std::shared_ptr<Multiply>;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_MULTIPLY
