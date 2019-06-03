#ifndef FLUSTER_COMPILER_AST_OPS_NEGATE
#define FLUSTER_COMPILER_AST_OPS_NEGATE

#include "ast/expr.h"
#include "operator.h"

namespace fluster { namespace ast { namespace ops {



struct Negate final
    : public UnaryOperator
{
    //// Methods
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Construction
    Negate(Expr::Ptr in_operand);

    //// Types
    using Ptr = util::Ptr<Negate>;

    //// Class Constants
    static const std::string tag;
    static const std::string symbol;
};



} } }

#endif //FLUSTER_COMPILER_AST_OPS_NEGATE
