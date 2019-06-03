#include "power.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string Power::tag = "power";
const std::string Power::symbol = "^";

//// Methods

llvm::Value*
Power::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Power::tag>(ctx);
}

void
Power::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Power::symbol>(os, indent_level);
}

//// Construction

Power::
Power(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
