#ifndef FLUSTER_COMPILER_DB_PATH
#define FLUSTER_COMPILER_DB_PATH

#include <deque>
#include <exception>
#include "name.h"

namespace fluster { namespace db {



using Path = std::deque<Name>;

extern const Path root_path;

struct ElementNotFound final
    : public std::exception
{
    const char* what() const noexcept final;
    Path element_path;
};

Path operator+(const Path& lhs, const Path& rhs);



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
