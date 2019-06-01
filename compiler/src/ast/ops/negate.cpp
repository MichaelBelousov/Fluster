#include "negate.h"

namespace fluster { namespace ast { namespace ops {



Negate::
Negate(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(Negate, "-")



} } }
