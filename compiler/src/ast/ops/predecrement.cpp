#include "predecrement.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string PreDecrement::tag = "predecrement";
const std::string PreDecrement::symbol = "--";

//// Methods

llvm::Value*
PreDecrement::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<PreDecrement::tag>(ctx);
}

void
PreDecrement::
print(std::ostream& os, unsigned indent_level) const
{
    _print<PreDecrement::symbol>(os, indent_level);
}

//// Construction

PreDecrement::
PreDecrement(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}



} } }
