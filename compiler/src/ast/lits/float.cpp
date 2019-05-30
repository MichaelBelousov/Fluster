#include <memory>
#include "atoms/types.h"
#include "ast/expr.h"

namespace fluster { namespace ast { namespace lits {



//// Construction

Float::
Float( const atoms::Rational& in_value )
    : value(in_value)
{}

Float::
Float( const atoms::Integer& in_numerator
     , const atoms::Integer& in_denominator
     )
    : Float(atoms::Rational(in_numerator, in_denominator))
{}



} } }  //namespace fluster::ast::lits
