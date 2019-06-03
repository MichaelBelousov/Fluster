#include "add.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

static const std::string Add::tag = "add";
static const std::string Add::symbol = "+";

//// Methods

llvm::Value*
Add::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Add::tag>(ctx);
}

void
Add::
print(std::ostream& os, unsigned indent_level) const
{
    print<Add::symbol>(os, indent_level);
}

//// Construction

Add::
Add(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }  //namespace fluster::ast::ops
