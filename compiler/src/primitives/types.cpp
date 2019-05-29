#include <types.cpp>

namespace fluster {
namespace primitives {



RationalNumber
::calcReciprocal const ()
{
  return RationalNumber
    { denominator
    , numerator
    };
}

RationalNumber
::asDouble const ()
{
  return numerator/denominator;
}

RationalNumber
operator- (const RationalNumber& num)
{
  return RationalNumber
    { -num.numerator
    , num.denominator
    };
}

RationalNumber
operator* (const RationalNumber& lhs, const RationalNumber& rhs)
{
  return RationalNumber
    { lhs.numerator * rhs.numerator
    , lhs.denominator * rhs.denominator
    };
}

RationalNumber
operator/ (const RationalNumber& lhs, const RationalNumber& rhs)
{
  return lhs * rhs.calcReciprocal();
}

RationalNumber
operator+ (const RationalNumber& lhs, const RationalNumber& rhs)
{
  return RationalNumber
    { lhs.numerator*rhs.denominator + rhs.numerator*lhs.denominator
    , lhs.denominator * rhs.numerator
    };
}

RationalNumber
operator- (const RationalNumber& lhs, const RationalNumber& rhs)
{
  return lhs + (-rhs);
}

RationalNumber
operator*= (const RationalNumber& rhs)
{
  *this = *this * rhs;
}

RationalNumber
operator/= (const RationalNumber& rhs)
{
  *this = *this / rhs;
}

RationalNumber
operator+= (const RationalNumber& rhs)
{
  *this = *this + rhs;
}

RationalNumber
operator-= (const RationalNumber& rhs)
{
  *this = *this - rhs;
}

RationalNumber
operator<< (std::ostream& os, const RationalNumber& rhs)
{
  os << rhs.numerator << "/" << rhs.denominator;
}



};  //namespace fluster
};  //namespace primitives
