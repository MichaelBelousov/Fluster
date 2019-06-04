#ifndef FLUSTER_COMPILER_ARG_PARSER
#define FLUSTER_COMPILER_ARG_PARSER

#include <string>
#include <vector>
#include <algorithm>

namespace fluster {



struct ArgParser
{
    //// Construction
    ArgParser(int argc, char* argv[]);

    //// Methods

    // TODO: use informative static_assert about all types having 
    // to be convertible to string
    template<typename Str, typename ...More>
    bool has_flag(Str flag, More ...flag_aliases)
    {
        std::vector<std::string> aliases = {flag, flag_aliases...};
        for (const auto& arg : args)
            for (const auto& alias : aliases)
                if (arg == alias)
                    return true;
        return false;
    }

    //// Members
    std::string program;  //first arg
    int arg_count;
    std::vector<std::string> args;
};



}  //namespace fluster

#endif //FLUSTER_COMPILER_ARG_PARSER
