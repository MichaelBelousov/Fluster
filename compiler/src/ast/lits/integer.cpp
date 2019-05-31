#include <iostream>
#include "integer.h"

namespace fluster { namespace ast { namespace lits {


//// Construction

/*
Integer::
Integer()
    : value()
{}
*/


Integer::
Integer(const atoms::Integer& in_value)
    : value(in_value)
{}


void
Integer::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<integer value=\"" << value << "\">" << std::endl;
}


} } }
