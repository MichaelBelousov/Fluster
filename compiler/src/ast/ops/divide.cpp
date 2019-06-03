#include "divide.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

static const std::string Divide::tag = "divide";
static const std::string Divide::symbol = "/";

//// Methods

llvm::Value*
Divide::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Divide::tag>(ctx);
}

void
Divide::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Divide::symbol>(os, indent_level);
}

//// Construction

Divide::
Divide(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
