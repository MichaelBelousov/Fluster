#ifndef FLUSTER_COMPILER_DRIVER_H
#define FLUSTER_COMPILER_DRIVER_H

#include <string>
#include <map>
#include "parser.gen.h"

#define YY_DECL \
    yy::parser::symbol_type lex(Driver& d)

YY_DECL;

namespace Fluster {

struct ParseContext {
    std::map<std::string, int> variables;
    //Type expression_type;
    //Decl declaration_type;
};

/* Driver for connecting the lexer and parser
 * with a context
 */
struct Driver {
    /// Members
    ParseContext context;
    bool trace_lexing;
    bool trace_parsing;
    yy::location location;
    std::string file_path;

    /// Construction
    Driver();

    /// Methods
    int parse(const std::string& in_file_path);
    void begin_lexing();
    void end_lexing();
};


};  //namespace Fluster

#endif //FLUSTER_COMPILER_DRIVER_H
