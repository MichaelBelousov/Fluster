#include "db/path.h"
#include <algorithm>

namespace fluster { namespace db {



const Path root_path = {};


const char*
ElementNotFound::
what() const noexcept
{
    return "element not found";
}


Path operator+ (const Path& lhs, const Path& rhs)
{
    Path result = lhs;
    std::copy(rhs.begin(), lhs.end(), std::back_inserter(result));
    return result;
}



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
