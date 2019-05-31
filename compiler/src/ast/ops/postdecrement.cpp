#include "postdecrement.h"

namespace fluster { namespace ast { namespace ops {



PostDecrement::
PostDecrement(Expr::Ptr in_operand)
    : UnaryOperator("--", in_operand)
{}



} } }
