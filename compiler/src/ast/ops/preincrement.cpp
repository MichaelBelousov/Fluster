#include "preincrement.h"

namespace fluster { namespace ast { namespace ops {



PreIncrement::
PreIncrement(Expr::Ptr in_operand)
    : UnaryOperator(in_operand)
{}

FLUSTER_COMPILER_OP_PRINT_IMPL(PreIncrement, "++")



} } }
