#ifndef FLUSTER_COMPILER_DB_PATH
#define FLUSTER_COMPILER_DB_PATH

#include <deque>
#include <exception>
#include "name.h"

namespace fluster { namespace db {



struct Path final
    : public std::deque<Name>
{
    //// Constants
    static const Path root_path;

    //// Methods
    Path next();
    static Path join(const Path& lhs, const Path& rhs);

    //// Construction
    using std::deque<Name>::deque;

    //// Friends
    friend Path operator+(const Path& lhs, const Path& rhs);
    friend bool operator==(const Path& lhs, const Path& rhs);
    friend bool operator==(const Path& lhs, const Name& rhs);
    friend bool operator==(const Name& lhs, const Path& rhs);
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
