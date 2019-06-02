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
    //// Construction
    Rational( const Integer& in_numerator
            , const Integer& in_denominator
            , const Integer& in_exponent = 1
            );

    //// Methods
    Rational calcReciprocal() const;
    double asDouble() const;
    Rational operator-() const;
    friend Rational operator*(const Rational& lhs, const Rational& rhs);
    friend Rational operator/(const Rational& lhs, const Rational& rhs);
    friend Rational operator+(const Rational& lhs, const Rational& rhs);
    friend Rational operator-(const Rational& lhs, const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);

private:
    //// Members
    Integer numerator;
    Integer denominator;
    Integer exponent;
};

using ByteArray = std::vector<Byte>;

using BitArray = std::vector<bool>;

using String = std::string;



} }  //namespace fluster::atoms

#endif //FLUSTER_COMPILER_ATOMS_TYPES
