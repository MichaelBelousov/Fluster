#ifndef FLUSTER_COMPILER_DATA_TYPE
#define FLUSTER_COMPILER_DATA_TYPE

#include <memory>
#include <vector>
#include "util/ptr.h"

// TODO: use rtti for runtime type querying?
namespace fluster { namespace data {



struct Type
    : public std::enable_shared_from_this<Type>
{
    //// Types
    using Ptr = util::Ptr<Type>;

    //// Methods
    //virtual Type::Ptr cloneof() const noexcept;

    //const Type::Ptr typeof() const noexcept override;

    //const bool is(Type::Ptr other) const noexcept;

    //const bool has(Type::Ptr other) const noexcept;

    static Type::Ptr makeInheritor() noexcept;

    static Type::Ptr makeImplementor() noexcept;

    //// Construction
    Type() = default;

private:
    std::vector<Type::Ptr> children;
    Type::Ptr parent;
};


// the type of types in type expressions (e.g. type of a type in templates)
extern Type TypeType;



} } //namespace fluster::data

#endif //FLUSTER_COMPILER_DATA_TYPE
