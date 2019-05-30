#ifndef FLUSTER_COMPILER_ATOMS_TYPES
#define FLUSTER_COMPILER_ATOMS_TYPES
//maybe add a build step that generates header include guards?

//#include <BigIntegerLibrary.hh>
using BigInteger = long long int;
using Byte = unsigned char;
#include <vector>
#include <iostream>

namespace fluster {
namespace atoms {



using Integer = BigInteger;

struct Rational
{
    Integer numerator;
    Integer denominator;

    Rational calcReciprocal() const;
    double asDouble() const;
    Rational operator-(const Rational& num);
    friend Rational operator*(const Rational& lhs, const Rational& rhs);
    friend Rational operator/(const Rational& lhs, const Rational& rhs);
    friend Rational operator+(const Rational& lhs, const Rational& rhs);
    friend Rational operator-(const Rational& lhs, const Rational& rhs);
    Rational operator*=(const Rational& rhs);
    Rational operator/=(const Rational& rhs);
    Rational operator+=(const Rational& rhs);
    Rational operator-=(const Rational& rhs);
    friend Rational operator<<(std::ostream& os, const Rational& rhs);
};

using ByteArray = std::vector<Byte>;

using BitArray = std::vector<bool>;

using String = std::string;



} }  //namespace fluster::atoms

#endif //FLUSTER_COMPILER_ATOMS_TYPES
