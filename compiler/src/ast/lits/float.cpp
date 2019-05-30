#include "float.h"

namespace fluster { namespace ast { namespace lits {



//// Construction

Float::
Float( const atoms::Rational& in_value )
    : value(in_value)
{}



} } }  //namespace fluster::ast::lits
