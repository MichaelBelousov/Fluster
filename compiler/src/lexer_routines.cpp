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
    return yy::Parser::make_IntegerLiteral(
        fluster::ast::lits::Integer::Ptr::make(n),
        loc
    );
}


yy::Parser::symbol_type 
make_FloatLiteral( std::string s
                 , const yy::Parser::location_type& loc
                 )
{
    const auto s_len = s.size();
    const auto radix_idx = std::find(s.begin(), s.end(), '.');
    // FIXME: do not ignore the exponent, it is blasphemously incorrect
    // *then why allow it in the parser if we're not supporting it yet?*
    const auto exponent_start = std::find_if(s.begin(), s.end(),
                                    [](const auto& c){return c=='e'||c=='E';});
    // NOTE: assume radix exists (assume the lexer works lol)
    const auto digits_before_radix = static_cast<int>(radix_idx - s.begin());
    // find returns s.end() if there is no exponent start, so we don't need
    // a condition
    const auto digits_after_radix = static_cast<int>(exponent_start - radix_idx - 1);

    // HACK: remove . for strtoll reading of numerator
    // requires pass-by-value
    s.erase(radix_idx);

    // FIXME: use atoms::Integer::parse to store big integers
    const auto numerator = strtoll(s.c_str(), NULL, 10);
    if ( numerator <= std::numeric_limits<long long>::min()
      || numerator >= std::numeric_limits<long long>::max()
      || errno == ERANGE
       )
        throw yy::Parser::syntax_error (loc, "float is out of range... ummm...: " + s);
    // TODO: add an intpow math function
    const auto denominator = std::pow(10, digits_after_radix);

    return yy::Parser::make_FloatLiteral(
        fluster::ast::lits::Float::Ptr::make(fluster::atoms::Rational(
                numerator,
                denominator)),
        loc
    );
}


yy::Parser::symbol_type
make_StringLiteral( const std::string &s
                  , const yy::Parser::location_type& loc
                  )
{
    return yy::Parser::make_StringLiteral(
        fluster::ast::lits::String::Ptr::make(s),
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
