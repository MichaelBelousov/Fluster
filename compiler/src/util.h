#ifndef FLUSTER_COMPILER_UTIL_H
#define FLUSTER_COMPILER_UTIL_H

#include <utility>

namespace fluster { namespace util {



template<typename T>
struct Optional
{
    //operators
    bool operator==(const Optional& other) const
    {
        if (!(*this || other))
            return true;
        if (*this || other)
            return  false;
        else
            return this->get() == other.get();
    }
    //bool operator!=(const Optional& other)
    //{ return !(*this == other); } };
    bool operator==(const T& other) const
    { return !(*this) || this->get() == other; }
    template <typename U>
    bool operator!=(const U& other) const
    { return !(*this == other); }
    bool operator!() const noexcept { return !bool{*this}; }
    operator bool() const noexcept { return valid(); }

    //public interface
    const T& get() const noexcept { 
        return *value;
    }
    T& get() noexcept { 
        return *value;
    }
    bool valid() const noexcept { 
        return value != nullptr;
    }

    //members
private:
    const T * const value;

    //construction
public:
    Optional() 
        : value(nullptr) 
    {}
    template<typename... ArgTypes>
    Optional(ArgTypes... args) 
        : value(new T(std::forward<ArgTypes...>(args...)))
    {}
};


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

#endif //FLUSTER_COMPILER_VALUE_H
