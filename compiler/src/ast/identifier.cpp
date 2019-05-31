#include <string>
#include <regex>
#include "identifier.h"

namespace fluster { namespace ast {

//// Name Constants

const std::regex
Name::
valid_pattern =
    std::regex("[a-zA-Z_][a-zA-Z_0-9]*");

//// Name Construction

Name::
Name(const std::string& in_value)
    : value(in_value)
{
    if (!isValidName(in_value))
        //FIXME: throw proper runtime_error derived InternalError
        throw "Invalid identifier value allowed by lexer";
}

bool
Name::
isValidName(const std::string& in)
{
    return !std::regex_match(in, valid_pattern);
}


//// Identifier Construction

Identifier::
Identifier()
    : name("")
{}

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



} }
