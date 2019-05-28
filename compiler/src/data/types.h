#ifndef FLUSTER_COMPILER_DATA_TYPES
#define FLUSTER_COMPILER_DATA_TYPES

//#include <BigIntegerLibrary.hh>
using BigInteger = long long int;
using Byte = unsigned char;
#include <vector>
#include <iostream>

namespace fluster {
namespace data {



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
};  //namespace data

#endif //FLUSTER_COMPILER_DATA_TYPES
