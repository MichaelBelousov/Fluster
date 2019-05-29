#ifndef FLUSTER_COMPILER_AST_OPS_SUBTRACT
#define FLUSTER_COMPILER_AST_OPS_SUBTRACT

#include <memory>
#include "ast/node.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Subtract final
    : public BinaryOperator
{
    //// Methods

    //// Construction
    Subtract( Expr::Ptr left_operand
            , Expr::Ptr right_operand
            );

    //// Types
    using Ptr = std::shared_ptr<Subtract>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_SUBTRACT
