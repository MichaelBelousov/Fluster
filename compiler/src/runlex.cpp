
#include <iostream>
#include "lexer.gen.h"
#include "parser.gen.h"

using yy::Lexer;

int main()
{
    std::ios::sync_with_stdio(false);

    Lexer lexer(std::cin);

    for (auto lexeme = lexer.lex();
         lexeme != yy::Parser::END;
         lexeme = lexer.lex())
        std::cout << lexeme << std::endl;

    return 0;
}
