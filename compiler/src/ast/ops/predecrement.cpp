#include "predecrement.h"

namespace fluster { namespace ast { namespace ops {



PreDecrement::
PreDecrement(Expr::Ptr in_operand)
{
    operand = in_operand;
}



} } }
