#include "comma_delimited_list.h"
#include "expr.h"
#include "lambda.h"

namespace fluster { namespace ast {



Lambda::
Lambda( CommaDelimitedList::Ptr in_args
      , Expr::Ptr in_body
      )
    : args(in_args)
    , body(in_body)
{}



} }
