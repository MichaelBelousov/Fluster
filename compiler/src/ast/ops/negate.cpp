#include "negate.h"

namespace fluster { namespace ast { namespace ops {



Negate::
Negate(Expr::Ptr in_operand)
    : UnaryOperator("-", in_operand)
{}



} } }
