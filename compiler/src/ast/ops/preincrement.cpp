#include "preincrement.h"

namespace fluster { namespace ast { namespace ops {



PreIncrement::
PreIncrement(Expr::Ptr in_operand)
{
    operand = in_operand;
}



} } }