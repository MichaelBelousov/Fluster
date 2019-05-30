#include "types.h"

namespace fluster {
namespace atoms {



//// Construction

Rational::
Rational(const Integer& in_numerator, const Integer& in_denominator)
    : numerator(in_numerator)
    , denominator(in_denominator)
{}

// build a rational from a floating point number
Rational::
Rational(double in_value)
{
    // FIXME: use David Eppstein's fractional approximation for real numbers
    // FIXME: this doesn't work for a large class of inputs and is only temporary
    constexpr const long long LARGE_VALUE = 1000000;
    numerator = static_cast<int>(in_value * LARGE_VALUE);
    denominator = LARGE_VALUE;
}

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
    return os << rhs.numerator << "/" << rhs.denominator;
}



} }  //namespace fluster::atoms
