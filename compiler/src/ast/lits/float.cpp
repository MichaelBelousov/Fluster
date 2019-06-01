#include "float.h"

namespace fluster { namespace ast { namespace lits {


//// Construction

Float::
Float()
    : value(0)
{}

Float::
Float( const atoms::Rational& in_value )
    : value(in_value)
{}

void
Float::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<float value=\"" << value << "\">" << std::endl;
}



} } }  //namespace fluster::ast::lits
