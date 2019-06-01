#include <iostream>
#include "lexer.gen.h"
#include "parser.gen.h"
#include "ast/ast.h"

using yy::Lexer, yy::Parser;

int main(/*int argc, char* argv[]*/)
{
    std::ios::sync_with_stdio(false);

    auto parse_result = fluster::ast::Node::makeRootNode();

    Lexer lexer(std::cin);
    Parser parser(lexer, parse_result);
    parser.set_debug_level(3);

    if (parser.parse() != 0)
        return -1;
    else {
        std::cout << std::endl << "Result:" << std::endl;
        std::cout << *parse_result << std::endl;
        return 0;
    }
}
