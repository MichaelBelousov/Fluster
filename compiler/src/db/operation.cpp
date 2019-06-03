#include <vector>
#include <functional>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "db/program_element.h"

namespace fluster { namespace db {



//// Construction

// TODO: use makeElement
Operation::
Operation( const Name& in_name
         , TypePtr in_return_type
         , const std::vector<TypePtr>& in_arg_types
         , const std::function<CallableImpl>& in_code_generator
         )
    : ProgramElement(in_name)
    , return_type(in_return_type)
    , in_arg_types(in_arg_types)
    , in_code_generator(in_code_generator)
{}

//// Operations

friend bool operator< (const Operation& lhs, const Operation& rhs)
{
    return lhs.name < lhs.rhs;
}



} } //namespace fluster::db
