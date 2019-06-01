#include "postdecrement.h"

namespace fluster { namespace ast { namespace ops {



PostDecrement::
PostDecrement(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(PostDecrement, "--")



} } }
