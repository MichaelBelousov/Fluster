#ifndef FLUSTER_COMPILER_DB_PATH
#define FLUSTER_COMPILER_DB_PATH

#include <deque>
#include <exception>
#include "name.h"

namespace fluster { namespace db {



struct Path final
    : public std::deque<Name>
{
    //// Types
    struct NoSuchElement;

    //// Constants
    static const Path root_path;

    //// Methods
    Path next(const Path& path);
    Path join(const Path& lhs, const Path& rhs);

    //// Friends
    friend Path operator+(const Path& lhs, const Path& rhs);
};

struct Path::NoSuchElement final
    : public std::exception
{
    const char* what() const noexcept final;
    Path element_path;
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
