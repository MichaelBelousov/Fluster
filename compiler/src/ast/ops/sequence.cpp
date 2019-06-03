#include "sequence.h"

namespace fluster { namespace ast { namespace ops {


//// Class Constants

const std::string Sequence::tag = "sequence";
const std::string Sequence::symbol = ";";

//// Methods

llvm::Value*
Sequence::
generateCode(GenerationContext& ctx) const
{
    return _generateCode<Sequence::tag>(ctx);
}

void
Sequence::
print(std::ostream& os, unsigned indent_level) const
{
    _print<Sequence::symbol>(os, indent_level);
}

//// Construction

Sequence::
Sequence(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator(in_lhs, in_rhs)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(Sequence, ";")



} } }
