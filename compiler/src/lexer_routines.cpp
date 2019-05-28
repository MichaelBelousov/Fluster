#include "lexer_routines.h"

#include <cmath>

namespace fluster {



BitBuffer
::BitBuffer(int in_bits)
    : bytes_len(std::ceil(in_bits/8.f))
    , length(in_bits)
    , bytes(new unsigned char[bytes_len])
{
    std::memset(bytes, 0, sizeof(unsigned char)*bytes_len);
}

BitBuffer
::~BitBuffer()
{
    delete[] bytes;
}

void setBits( unsigned bit_offset
            , unsigned int bits_len
            , unsigned char bits
            , unsigned char bytes[]
            )
{
    using cuint = const unsigned;
    cuint left_byte_id = bit_offset/8;
    cuint left_bound = bit_offset % 8;
    cuint right_byte_id = (bit_offset-1+bits_len)/8;
    cuint right_bound = (bit_offset-1+bits_len) % 8;

    if (left_byte_id == right_byte_id)
        bytes[right_byte_id] |= bits << (8-(right_bound+1));
    else
    {
        bytes[right_byte_id] |= bits << (8-(right_bound+1));
        bytes[left_byte_id] |= bits >> (left_bound - (8-bits_len));
    }
}


yy::Parser::symbol_type 
make_DECIMAL_INTEGER (const std::string &s, const yy::Parser::location_type& loc)
{
    errno = 0;  //XXX: WHY?
    long long n = strtoll (s.c_str(), NULL, 10);
    // FIXME: use fluster::data::Natural class to store any size integer
    if (n <= INT_MIN || n >= INT_MAX || errno == ERANGE)
        throw yy::Parser::syntax_error (loc, "integer is out of range: " + s);
    return yy::Parser::make_NUMBER(n, loc);
}


yy::Parser::symbol_type 
make_DECIMAL_FLOAT(const std::string &s, const yy::Parser::location_type& loc)
{
}

/* byte literals */
yy::Parser::symbol_type 
make_HEX_BYTES (const std::string &s, const yy::Parser::location_type& loc)
{
    auto Buffer = loadAsciiBitLiteral<16>(s, "0x");
    yylval.bytes = Buffer.bytes;
    return toks::lits::byte_;
}


yy::Parser::symbol_type 
make_BINARY_BITS (const std::string &s, const yy::Parser::location_type& loc)
{
    auto Buffer = loadAsciiBitLiteral<2>(s, "0b");
    yylval.bytes = bytes;
    return toks::lits::bit_;
}

yy::Parser::symbol_type 
make_OCTAL_BITS (const std::string &s, const yy::Parser::location_type& loc)
{
    auto Buffer = loadAsciiBitLiteral<8>(s, "0o");
    yylval.bytes = Buffer.bytes;
    return toks::lits::oct_;
}



};  // namespace fluster
