#include <iostream>
#include "lexer.gen.h"
#include "parser.gen.h"
#include "ast/ast.h"

using yy::Lexer, yy::Parser;

int main(/*int argc, char* argv[]*/)
{
    std::ios::sync_with_stdio(false);

    //auto result_root = fluster::ast::Node::Ptr::make();

    Lexer lexer(std::cin);
    Parser parser(lexer/*, result_root*/);

    if (parser.parse() != 0)
        return -1;
    else
        return 0;
}
