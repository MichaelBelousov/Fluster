#include "expr.h"

namespace fluster { namespace ast {



Expr::
Expr(db::Type::Ptr in_result_type)
    : result_type(in_result_type)
{}



} }  //namespace fluster::ast
