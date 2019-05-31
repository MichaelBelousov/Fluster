#include "root.h"

namespace fluster { namespace ast { namespace ops {



Root::
Root(Expr::Ptr in_lhs, Expr::Ptr in_rhs)
    : BinaryOperator("^/", in_lhs, in_rhs)
{}



} } }
