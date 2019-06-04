#include "lexer_routines.h"
#include "parser.gen.h"
#include "atoms/types.h"
#include "ast/identifier.h"

#include <cmath>
#include <limits>
#include <algorithm>


BitBuffer::
BitBuffer(int in_bits)
    : bytes_len(std::ceil(in_bits/8.f))
    , length(in_bits)
    , bytes(new unsigned char[bytes_len])
{
    std::memset(bytes, 0, sizeof(unsigned char)*bytes_len);
}


BitBuffer::
~BitBuffer()
{
    delete[] bytes;
}


void setBits( const unsigned bit_offset
            , const unsigned int bits_len
            , const unsigned char bits
            ,       unsigned char bytes[]
            )
{
    using cu32 = const unsigned;
    cu32 left_byte_id = bit_offset / 8;
    cu32 left_bound = bit_offset % 8;
    cu32 right_byte_id = (bit_offset-1+bits_len) / 8;
    cu32 right_bound = (bit_offset-1+bits_len) % 8;

    if (left_byte_id == right_byte_id)
        bytes[right_byte_id] |= bits << (8-(right_bound+1));
    else
    {
        bytes[right_byte_id] |= bits << (8-(right_bound+1));
        bytes[left_byte_id] |= bits >> (left_bound - (8-bits_len));
    }
}

yy::Parser::symbol_type 
make_Identifier( const std::string &s
               , const yy::Parser::location_type& loc
               )
{
    return yy::Parser::make_Identifier(
        fluster::ast::Identifier::Ptr::make(s),
        loc
    );
}


yy::Parser::symbol_type 
make_IntegerLiteral( const std::string &s
                   , const yy::Parser::location_type& loc
                   )
{
    // FIXME: use atoms::Integer::parse to store big integers
    errno = 0;  // XXX: WHY?
    fluster::atoms::Integer n = strtoll(s.c_str(), NULL, 10);
    if ( n <= std::numeric_limits<long long>::min()
      || n >= std::numeric_limits<long long>::max()
      || errno == ERANGE
       )
        throw yy::Parser::syntax_error (loc, "integer is out of range: " + s);

    constexpr const unsigned num_bits = 64;
    return yy::Parser::make_IntegerLiteral(
        fluster::ast::lits::Integer::Ptr::make(num_bits, n, /*signed=*/true),
        loc
    );
}


// NOTE: assumes a radix exists as per the lexer specification. Undefined
// behaviour otherwise
yy::Parser::symbol_type 
make_FloatLiteral( std::string s
                 , const yy::Parser::location_type& loc
                 )
{
    // PRECONDITION: float format literal is valid
    // TODO: add debug-enabled precondition checking
    // TODO: add precondition declaration macro
    const auto p_radix = std::find(s.begin(), s.end(), '.');
    const auto p_exponent_start = std::find_if(s.begin(), s.end(),
                                    [](const auto& c){return c=='e'||c=='E';});
    // find returns s.end() if there is no exponent start
    const auto num_digits_after_radix = static_cast<int>(p_exponent_start - p_radix - 1);

    // shift out radix
    for(auto i = p_radix; i < p_exponent_start-1; ++i)
        *i = *(i+1);
    *(p_exponent_start-1) = '\0';

    // FIXME: use atoms::Integer::parse to store big integers
    const auto exponent = strtoll(
        s.c_str() + static_cast<int>(p_exponent_start-s.begin()) + 1,  //advance to p_exponent_start
        nullptr, 10
    );
    if ( exponent <= std::numeric_limits<long long>::min()
      || exponent >= std::numeric_limits<long long>::max()
      || errno == ERANGE
       )
        throw yy::Parser::syntax_error (loc, "float exponent is out of range: " + s);

    const auto numerator = strtoll(s.c_str(), nullptr, 10);
    if ( numerator <= std::numeric_limits<long long>::min()
      || numerator >= std::numeric_limits<long long>::max()
      || errno == ERANGE
       )
        throw yy::Parser::syntax_error (loc, "float significand is out of range: " + s);

    const auto denominator = std::pow(10, num_digits_after_radix);

    return yy::Parser::make_FloatLiteral(
        fluster::ast::lits::Float::Ptr::make(fluster::atoms::Rational(
                numerator,
                denominator,
                exponent)),
        loc
    );
}


yy::Parser::symbol_type
make_StringLiteral( const std::string &s
                  , const yy::Parser::location_type& loc
                  )
{
    // PRECONDITION: assumes string literal format
    // and length of 2 given quotes
    const auto strlen = s.length();
    return yy::Parser::make_StringLiteral(
        fluster::ast::lits::String::Ptr::make(s.substr(1, strlen-2)),
        loc
    );
}

/*
yy::Parser::symbol_type 
make_HexBytesLiteral (const std::string &s, const yy::Parser::location_type& loc)
{
    auto buffer = loadAsciiBitLiteral<16>(s, "0x");
    return yy::Parser::make_BytesLiteral(buffer.bytes, loc);
}


yy::Parser::symbol_type 
make_BinaryBitsLiteral (const std::string &s, const yy::Parser::location_type& loc)
{
    auto buffer = loadAsciiBitLiteral<2>(s, "0b");
    return yy::Parser::make_BitsLiteral(buffer.bytes, loc);
}

yy::Parser::symbol_type 
make_OctalBitsLiteral (const std::string &s, const yy::Parser::location_type& loc)
{
    auto buffer = loadAsciiBitLiteral<8>(s, "0o");
    return yy::Parser::make_BitsLiteral(buffer.bytes, loc);
}
*/
