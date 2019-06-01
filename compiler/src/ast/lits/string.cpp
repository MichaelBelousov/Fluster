#include "string.h"

namespace fluster { namespace ast { namespace lits {


//// Construction

String::
String(const atoms::String& in_value)
    : value(in_value)
{}

void
String::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<string value=\"" << value << "\">" << std::endl;
}



} } }
