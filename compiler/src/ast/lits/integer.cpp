#include "integer.h"

namespace fluster { namespace ast { namespace lits {


//// Construction

Integer::
Integer()
    : value()
{}

Integer::
Integer(const atoms::Integer& in_value)
    : value(in_value)
{}



} } }
