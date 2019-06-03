#ifndef FLUSTER_COMPILER_NAME
#define FLUSTER_COMPILER_NAME

#include <string>
#include <regex>

namespace fluster {



struct Name final
{
    //// Construction
    Name(const std::string& in_value);

    //// Members
    const std::string value;

private:
    //// Methods
    static bool isValidName(const std::string& in);

    //// Constants
    static const std::regex valid_pattern;
};



}  //namespace fluster

#endif //FLUSTER_COMPILER_NAME
