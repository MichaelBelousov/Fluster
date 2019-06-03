#include "subtract.h"
// TODO: rename to difference?

namespace fluster { namespace ast { namespace ops {



//// Class Constants

static const std::string SquareRoot::tag = "subtract";
static const std::string SquareRoot::symbol = "-";

//// Methods

llvm::Value*
Subtract::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Subtract::tag>(ctx);
}

void
Subtract::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Subtract::symbol>(os, indent_level);
}

//// Construction

Subtract::
Subtract(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }  //namespace fluster::ast::ops
