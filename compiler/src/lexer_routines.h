#ifndef FLUSTER_COMPILER_LEXER_ROUTINES
#define FLUSTER_COMPILER_LEXER_ROUTINES

#include <cmath>

namespace fluster {



struct BitBuffer
{
    unsigned int bytes_len;
    unsigned int length;
    unsigned char* bytes;
    BitBuffer(int in_bits);
    ~BitBuffer();
};

void setBits( unsigned bit_offset
            , unsigned int bits_len
            , unsigned char bits
            , unsigned char bytes[]
            );


template<int base>
BitBuffer loadAsciiBitLiteral( const std::string& literal
                             , const std::string& prefix
                             )
{
    static_assert(base <= 36, "only 26 letters + 10 numbers supported");

    const int bits_per_char = std::log2(base);
    const int bit_amt = (literal.length() - prefix.length()) * bits_per_char;
    const int byte_amt = std::ceil(bit_amt/8.f);

    auto result = BitBuffer(bit_amt);

    const int bit_padding = (byte_amt*8) - bit_amt;
    int depth = bit_padding;
    for (auto itr = literal.cbegin()+prefix.length(); 
         itr != literal.cend();
         ++itr, depth+=bits_per_char)
    { 
        unsigned char bits;
        if (*itr  <= 57) //is an ascii number
             bits = *itr  - 48;
        else            //is an ascii letter
            bits = (*itr | (1<<5)) - 87;
        setBits(depth, bits_per_char, bits, result.bytes);
    }
    return result;
}

yy::Parser::symbol_type 
make_DECIMAL_INTEGER( const std::string &s
                    , const yy::Parser::location_type& loc
                    );


yy::Parser::symbol_type 
make_DECIMAL_FLOAT( const std::string &s
                  , const yy::Parser::location_type& loc
                  ); 

/* byte literals */
yy::Parser::symbol_type 
make_HEXBYTES( const std::string &s
             , const yy::Parser::location_type& loc
             );

yy::Parser::symbol_type 
make_BINARY_BITS( const std::string &s
                , const yy::Parser::location_type& loc
                );

yy::Parser::symbol_type 
make_OCTAL_BITS( const std::string &s
               , const yy::Parser::location_type& loc
               );

//yy::parser::symbol_type 
//make_STRING (const std::string &s, const yy::parser::location_type& loc);

//yy::parser::symbol_type 
//make_UNICODESTRING (const std::string &s, const yy::parser::location_type& loc);

//yy::parser::symbol_type 
//make_RAWSTRING (const std::string &s, const yy::parser::location_type& loc); 

}; //namespace Fluster

#endif //FLUSTER_COMPILER_LEXER_ROUTINES
