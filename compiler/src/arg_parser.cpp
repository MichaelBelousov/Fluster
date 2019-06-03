#include "arg_parser.h"

namespace fluster {



//// Construction

// TODO: rename to argument database?
ArgParser::
ArgParser(int argc, char* argv[])
    : program(argv[0]) // TODO: embed a constructor initializer try/catch here
    , arg_count(argc)
    , args()
{
    args.reserve(argc-1);
    for (int i = 1; i < argc; ++i)
        args.emplace_back(argv[i]);
}



}  //namespace fluster
