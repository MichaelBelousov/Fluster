#ifndef FLUSTER_COMPILER_DB_TABLE
#define FLUSTER_COMPILER_DB_TABLE

#include <map>
//#include <unordered_map>

namespace fluster { namespace db {



template<typename ...Args>
using Table = std::map<Args...>;



} } //namespace fluster::db

#endif  //FLUSTER_COMPILER_DB_TABLE
