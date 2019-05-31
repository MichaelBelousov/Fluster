#include "predecrement.h"

namespace fluster { namespace ast { namespace ops {



PreDecrement::
PreDecrement(Expr::Ptr in_operand)
    : UnaryOperator("--", in_operand)
{}



} } }
