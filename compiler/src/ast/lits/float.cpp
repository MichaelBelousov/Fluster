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



} } }  //namespace fluster::ast::lits
