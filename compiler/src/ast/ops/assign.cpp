#include "assign.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

static const std::string Assign::tag = "assign";
static const std::string Assign::symbol = "=";

//// Methods

llvm::Value*
Assign::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Assign::tag>(ctx);
}

void
Assign::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Assign::symbol>(os, indent_level);
}

//// Construction

Assign::
Assign(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
