#include "driver.h"
#include "parser.h"

namespace Fluster {


/// Construction

Driver::Driver()
    : context()
    , trace_lexing(false)
    , trace_parsing(false)
    , location()
    , file_path()
{}

/// Methods

int Driver::parse(const std::string& in_file)
{
    int result;

    file_path = in_file;
    location.initialize(&file);

    begin_lexing();
    {
        yy::parser parse(*this);
        parse.set_debug_level(trace_parsing);
        result = parse();
    }
    end_lexing();

    return result;
}

void Driver::begin_lexing()
{
}

void Driver::end_lexing()
{
}


};  //namespace Fluster
