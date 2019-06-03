#include "assert_type.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

static const std::string AssertType::tag = "type_assert";
static const std::string AssertType::symbol = ":";

//// Methods

llvm::Value*
AssertType::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<AssertType::tag>(ctx);
}

void
Assign::
print(std::ostream& os, unsigned indent_level) const
{
    _print<AssertType::symbol>(os, indent_level);
}

//// Construction


AssertType::
AssertType(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}



} } }
