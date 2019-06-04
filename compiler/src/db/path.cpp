#include "db/path.h"
#include <algorithm>

namespace fluster { namespace db {



//// Constants

const Path Path::root_path = {};

//// Path::ElementNotFound

const char*
Path::NoSuchElement::
what() const noexcept
{
    return "element not found";
}

//// Methods

Path
Path::
next(const Path& path)
{
    Path result = path;
    if (!path.empty())
        result.pop_front();
    return result;
}

Path 
Path::
join(const Path& lhs, const Path& rhs)
{
    return lhs + rhs;
}

Path operator+ (const Path& lhs, const Path& rhs)
{
    Path result = lhs;
    std::copy(rhs.begin(), lhs.end(), std::back_inserter(result));
    return result;
}



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
