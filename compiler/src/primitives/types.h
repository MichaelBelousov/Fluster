#ifndef FLUSTER_COMPILER_PRIMITIVES_TYPES
#define FLUSTER_COMPILER_PRIMITIVES_TYPES
//maybe add a build step that generates header include guards?

//#include <BigIntegerLibrary.hh>
using BigInteger = long long int;
using Byte = unsigned char;
#include <vector>
#include <iostream>

namespace fluster {
namespace primitives {



using NaturalNumber = BigInteger;
struct RationalNumber {
  NaturalNumber numerator;
  NaturalNumber denominator;

  RationalNumber calcReciprocal() const;
  double asDouble() const;
  RationalNumber operator-(const RationalNumber& num);
  friend RationalNumber operator*(const RationalNumber& lhs, const RationalNumber& rhs);
  friend RationalNumber operator/(const RationalNumber& lhs, const RationalNumber& rhs);
  friend RationalNumber operator+(const RationalNumber& lhs, const RationalNumber& rhs);
  friend RationalNumber operator-(const RationalNumber& lhs, const RationalNumber& rhs);
  RationalNumber operator*=(const RationalNumber& rhs);
  RationalNumber operator/=(const RationalNumber& rhs);
  RationalNumber operator+=(const RationalNumber& rhs);
  RationalNumber operator-=(const RationalNumber& rhs);
  friend RationalNumber operator<<(std::ostream& os, const RationalNumber& rhs);
};
using ByteArray = std::vector<Byte>;
using BitArray = std::vector<bool>;
using String = std::string;



};  //namespace fluster
};  //namespace primitives

#endif //FLUSTER_COMPILER_PRIMITIVES_TYPES
