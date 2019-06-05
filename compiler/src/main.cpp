#include <iostream>
#include "lexer.gen.h"
#include "parser.gen.h"
#include "arg_parser.h"
#include "ast/ast.h"
#include "context.h"
#include "db/program_database.h"
#include "db/primitives.h"

using yy::Lexer, yy::Parser;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);

    auto argparser = fluster::ArgParser(argc, argv);

    // TODO: add parser driver holding both and returning AST
    auto parse_result = fluster::ast::Node::makeRootNode();
    Lexer lexer(std::cin);
    Parser parser(lexer, parse_result);
    parser.set_debug_level(static_cast<int>(argparser.has_flag("-d", "--debug")));

    if (parser.parse() != 0)
    {
        std::cerr << "Parsing failed" << std::endl;
        return -1;
    }
    else
    {
        std::cout << std::endl << "ast:" << std::endl;
        std::cout << *parse_result << std::endl;

        std::cout << std::endl << "committing constructs:" << std::endl;
        fluster::GenerationContext ctx;
        fluster::db::commitPrimitives(ctx);
        parse_result->commit(ctx.db);

        std::cout << std::endl << "generating code" << std::endl;
        parse_result->generateCode(ctx);

        return 0;
    }
}
