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
    return std::regex_match(in, valid_pattern);
}


//// Operators


bool operator< (const Name& lhs, const Name& rhs)
{
    return lhs.value < rhs.value;
}


bool operator== (const Name& lhs, const Name& rhs)
{
    return lhs.value == rhs.value;
}


std::ostream& operator<< (std::ostream& os, const Name& name)
{
    os << name.value;
    return os;
}


//// InternalInvalidName


InternalInvalidName::
InternalInvalidName(const Name& in_name)
    : name(in_name)
{}

const char*
InternalInvalidName::
what() const noexcept
{
    // TODO: copy problematic name into buffer and show it
    std::string msg("Invalid name found internally, there might be a lexer bug");
    msg += name.value;
    return msg.c_str();
}



}  //namespace fluster
