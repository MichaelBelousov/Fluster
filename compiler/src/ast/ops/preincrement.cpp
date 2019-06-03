#include "preincrement.h"

namespace fluster { namespace ast { namespace ops {



//// Class Constants

const std::string PreIncrement::tag = "preincrement";
const std::string PreIncrement::symbol = "++";

//// Methods

llvm::Value*
PreIncrement::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<PreIncrement::tag>(ctx);
}

void
PreIncrement::
print(std::ostream& os, unsigned indent_level) const
{
    _print<PreIncrement::symbol>(os, indent_level);
}

//// Construction

PreIncrement::
PreIncrement(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}



} } }
