#ifndef FLUSTER_COMPILER_UTIL_PREALLOCATED_VECTOR_H
#define FLUSTER_COMPILER_UTIL_PREALLOCATED_VECTOR_H

#include <utility>

namespace fluster { namespace util {




// do NOT add any methods or members that would cause this object to
// be interpreted differently from a regular std::vector
template<typename T, std::size_t PreallocationAmt, typename ...VecRestArgs>
struct PreallocatedVector final
    : public std::vector<T, VecRestArgs...>
{
    PreallocatedVector()
        : std::vector<T, VecRestArgs...>()
    {
        this->reserve(PreallocationAmt);
    }
};



} }

#endif //FLUSTER_COMPILER_UTIL_PREALLOCATED_VECTOR_H
