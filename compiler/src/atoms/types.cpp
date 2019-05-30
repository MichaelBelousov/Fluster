#include "types.cpp"

namespace fluster {
namespace atoms {



Rational
Rational::
calcReciprocal const ()
{
    return Rational
        { denominator
            , numerator
        };
}

double
Rational::
asDouble const ()
{
    return numerator/denominator;
}

Rational
operator- (const Rational& num)
{
    return Rational
        { -num.numerator
            , num.denominator
        };
}

Rational
operator* (const Rational& lhs, const Rational& rhs)
{
    return Rational
        { lhs.numerator * rhs.numerator
            , lhs.denominator * rhs.denominator
        };
}

Rational
operator/ (const Rational& lhs, const Rational& rhs)
{
    return lhs * rhs.calcReciprocal();
}

Rational
operator+ (const Rational& lhs, const Rational& rhs)
{
    return Rational
        { lhs.numerator*rhs.denominator + rhs.numerator*lhs.denominator
            , lhs.denominator * rhs.numerator
        };
}

Rational
operator- (const Rational& lhs, const Rational& rhs)
{
    return lhs + (-rhs);
}

Rational
operator*= (const Rational& rhs)
{
    *this = *this * rhs;
}

Rational
operator/= (const Rational& rhs)
{
    *this = *this / rhs;
}

Rational
operator+= (const Rational& rhs)
{
    *this = *this + rhs;
}

Rational
operator-= (const Rational& rhs)
{
    *this = *this - rhs;
}

Rational
operator<< (std::ostream& os, const Rational& rhs)
{
    os << rhs.numerator << "/" << rhs.denominator;
}



}; };  //namespace fluster::atoms
