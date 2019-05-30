#include "lexer_routines.h"
#include "parser.gen.h"
#include "atoms/types.h"
#include "ast/identifier.h"

#include <cmath>
#include <limits>


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
        std::make_shared<fluster::ast::Identifier>(s),
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
    fluster::atoms::Integer n = strtoll (s.c_str(), NULL, 10);
    if ( n <= std::numeric_limits<long long>::min()
      || n >= std::numeric_limits<long long>::max()
      || errno == ERANGE
       )
        throw yy::Parser::syntax_error (loc, "integer is out of range: " + s);
    return yy::Parser::make_IntegerLiteral(
        std::make_shared<fluster::ast::lits::Integer>(n),
        loc
    );
}


yy::Parser::symbol_type 
make_FloatLiteral( const std::string &s
                 , const yy::Parser::location_type& loc
                 )
{
    char* _;
    double n = strtod(s.c_str(), &_);
    return yy::Parser::make_FloatLiteral(
        std::make_shared<fluster::ast::lits::Float>(
            fluster::atoms::Rational(n)),
        loc
    );
}


yy::Parser::symbol_type
make_StringLiteral( const std::string &s
                  , const yy::Parser::location_type& loc
                  )
{
    return yy::Parser::make_StringLiteral(
        std::make_shared<fluster::ast::lits::String>(s),
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
