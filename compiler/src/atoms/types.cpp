#include "types.h"

namespace fluster {
namespace atoms {



//// Construction

Rational::
Rational( const Integer& in_numerator
        , const Integer& in_denominator
        , const Integer& in_exponent
        )
    : numerator(in_numerator)
    , denominator(in_denominator)
    , exponent(in_exponent)
{}

//// Methods

Rational
Rational::
calcReciprocal() const
{
    return Rational
        { denominator
        , numerator
        };
}

double
Rational::
asDouble() const
{
    return numerator/denominator;
}

Rational
Rational::
operator- () const
{
    return Rational
        { -numerator
        , denominator
        };
}

Rational
operator* ( const Rational& lhs
          , const Rational& rhs
          )
{
    return Rational
        { lhs.numerator * rhs.numerator
        , lhs.denominator * rhs.denominator
        };
}

Rational
operator/ ( const Rational& lhs
          , const Rational& rhs
          )
{
    return lhs * rhs.calcReciprocal();
}

Rational
operator+ ( const Rational& lhs
          , const Rational& rhs
          )
{
    return Rational
        { lhs.numerator*rhs.denominator + rhs.numerator*lhs.denominator
        , lhs.denominator * rhs.numerator
        };
}

Rational
operator- ( const Rational& lhs
          , const Rational& rhs
          )
{
    return lhs + (-rhs);
}

Rational&
Rational::
operator*= (const Rational& rhs)
{
    return *this = *this * rhs;
}

Rational&
Rational::
operator/= (const Rational& rhs)
{
    return *this = *this / rhs;
}

Rational&
Rational::
operator+= (const Rational& rhs)
{
    return *this = *this + rhs;
}

Rational&
Rational::
operator-= (const Rational& rhs)
{
    return *this = *this - rhs;
}

std::ostream&
operator<< ( std::ostream& os
           , const Rational& rhs
           )
{
    return os
        << rhs.numerator << "/" << rhs.denominator
        << " x 10^" << rhs.exponent;
}



} }  //namespace fluster::atoms
