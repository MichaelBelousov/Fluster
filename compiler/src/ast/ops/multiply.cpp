#include "multiply.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string Multiply::tag = "multiply";
const std::string Multiply::symbol = "*";

//// Methods

llvm::Value*
Multiply::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Multiply::tag>(ctx);
}

void
Multiply::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Multiply::symbol>(os, indent_level);
}

//// Construction

Multiply::
Multiply(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
