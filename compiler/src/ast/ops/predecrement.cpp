#include "predecrement.h"

namespace fluster { namespace ast { namespace ops {



PreDecrement::
PreDecrement(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(PreDecrement, "--")



} } }
