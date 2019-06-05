#include "path.h"
#include <algorithm>
#include "program_database.h"

namespace fluster { namespace db {



//// Constants

const Path Path::root_path = {};

//// Methods

Path
Path::
next()
{
    Path result = *this;
    if (!result.empty())
        result.pop_front();
    return result;
}

//// Static Functions

Path 
Path::
join(const Path& lhs, const Path& rhs)
{
    return lhs + rhs;
}

//// Operators

Path operator+ (const Path& lhs, const Path& rhs)
{
    Path result = lhs;
    std::copy(rhs.begin(), lhs.end(), std::back_inserter(result));
    return result;
}

bool operator==(const Path& lhs, const Path& rhs)
{
    return lhs == rhs;
}

bool operator==(const Path& lhs, const Name& rhs)
{
    return lhs.size() == 1 && lhs[0] == rhs;
}

bool operator==(const Name& lhs, const Path& rhs)
{
    return rhs == lhs;
}



} } //namespace fluster::db
