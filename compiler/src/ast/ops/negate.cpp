#include "negate.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string Negate::tag = "negate";
const std::string Negate::symbol = "-";

//// Methods

llvm::Value*
Negate::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Negate::tag>(ctx);
}

void
Negate::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Negate::symbol>(os, indent_level);
}

//// Construction

Negate::
Negate(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}



} } }
