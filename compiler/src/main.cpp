#include <iostream>
#include "lexer.gen.h"
#include "parser.gen.h"

using yy::Lexer, yy::Parser;

int main(/*int argc, char* argv[]*/)
{
    std::ios::sync_with_stdio(false);

    Lexer lexer(std::cin);
    Parser parser(lexer);

    if (parser.parse() != 0)
        return -1;
    else
        return 0;
}
