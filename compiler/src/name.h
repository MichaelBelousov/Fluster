#ifndef FLUSTER_COMPILER_NAME
#define FLUSTER_COMPILER_NAME

#include <iostream>
#include <exception>
#include <string>
#include <regex>

namespace fluster {



struct Name final
{

    //// Construction
    // TODO: should probably just forward to string ctor
    Name(const std::string& in_value);
    Name(const char* in_value);

    //// Members
    const std::string value;

    //// Operators
    friend bool operator< (const Name& lhs, const Name& rhs);
    friend bool operator== (const Name& lhs, const Name& rhs);
    friend std::ostream& operator<< (std::ostream& os, const Name& name);

private:
    //// Methods
    static bool isValidName(const std::string& in);

    //// Constants
    static const std::regex valid_pattern;
};

struct InternalInvalidName final : public std::exception
{
    InternalInvalidName(const Name& name);
    const char* what() const noexcept final;
    const Name name;
};



}  //namespace fluster

#endif //FLUSTER_COMPILER_NAME
