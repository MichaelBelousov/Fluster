#ifndef FLUSTER_COMPILER_DRIVER_H
#define FLUSTER_COMPILER_DRIVER_H

#include <string>
#include <map>
#include "parser.gen.h"
#include "location.gen.h"

/*
#define YY_DECL \
    yy::Parser::symbol_type lex(Driver& d)

YY_DECL;
*/

//namespace fluster {



struct ParseContext {
    std::map<std::string, int> variables;
    //Type expression_type;
    //Decl declaration_type;
};

/* Driver for connecting the lexer and Parser
 * with a context
 */
struct Driver final {
    /// Members
    ParseContext context;
    bool trace_lexing;
    bool trace_parsing;
    yy::location location;
    std::string file_path;

    /// Construction
    Driver() noexcept;

    /// Methods
    int parse(const std::string& in_file_path) noexcept;
    void begin_lexing() noexcept;
    void end_lexing() noexcept;
};



//};  //namespace fluster

#endif //FLUSTER_COMPILER_DRIVER_H
