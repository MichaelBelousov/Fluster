#include <string>
#include <regex>
#include "name.h"

namespace fluster {



//// Name Constants


const std::regex
Name::
valid_pattern =
    std::regex("[a-zA-Z_][a-zA-Z_0-9]*");


//// Name Construction


Name::
Name(const char* in_value)
    : Name(std::string(in_value))
{}


Name::
Name(const std::string& in_value)
    : value(in_value)
{
    if (!isValidName(in_value))
        //FIXME: throw proper std::exception derived InternalError
        throw "Invalid identifier value allowed by lexer";
}


//// Methods


bool
Name::
isValidName(const std::string& in)
{
    return !std::regex_match(in, valid_pattern);
}


//// Operators


bool operator< (const Name& lhs, const Name& rhs)
{
    return lhs.value < rhs.value;
}



}  //namespace fluster
