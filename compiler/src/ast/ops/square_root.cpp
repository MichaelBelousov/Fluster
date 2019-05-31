#include "square_root.h"

namespace fluster { namespace ast { namespace ops {



SquareRoot::
SquareRoot(Expr::Ptr in_operand)
    : UnaryOperator("^/", in_operand)
{}



} } }
