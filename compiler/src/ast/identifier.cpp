#ifndef FLUSTER_COMPILER_AST_IDENTIFIER
#define FLUSTER_COMPILER_AST_IDENTIFIER

#include <string>
#include <regex>
#include "identifier.h"

namespace fluster { namespace ast {

//// Name Constants

//// Name Construction

Name::
Name(const std::string& in_value)
    : value(in_value)
{
    if (!isValidName(in_value))
        //FIXME: throw proper runtime_error derived InternalError
        throw "Invalid identifier value allowed by lexer"
}

const bool
Name::
isValidName(const std::string& in)
{
    constexpr std::regex
    return !std::regex_match(
            in_value,
            std::regex("[a-zA-Z_][a-zA-Z_0-9]*")
    );
}


//// Identifier Construction

Identifier::
Identifier(const std::string& in_name)
    : name(in_name)
{}

//// Identifier Methods
    
/*
const data::Construct::Ptr
Identifier::
finalize() const
{
    return data::Construct::Ptr();
}
*/



}; };

#endif //FLUSTER_COMPILER_AST_IDENTIFIER
