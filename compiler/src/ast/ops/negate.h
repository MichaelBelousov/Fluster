#ifndef FLUSTER_COMPILER_AST_OPS_NEGATE
#define FLUSTER_COMPILER_AST_OPS_NEGATE

#include <memory>
#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Negate final
    : public UnaryOperator
{
    //// Construction
    Negate(Expr::Ptr in_operand);

    //// Types
    using Ptr = std::shared_ptr<Negate>;
};



}; }; };

#endif //FLUSTER_COMPILER_AST_OPS_NEGATE
