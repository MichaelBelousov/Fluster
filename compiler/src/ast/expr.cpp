#include <iostream>
#include "expr.h"

namespace fluster { namespace ast {



void
Expr::
print(std::ostream& os, unsigned indent_level)
{
    for (int i = 0; i < indent_level; ++i) os << " ";
    os << "<EXPR/>" << std::endl;
}



} }
