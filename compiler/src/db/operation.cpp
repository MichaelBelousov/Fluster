#include <vector>
#include <functional>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "db/program_element.h"

namespace fluster { namespace db {



//// Methods

llvm::Value*
Operation::
getLLVMRepr(GenerationContext& ctx) const 
{
    // XXX: need to figure out dynamic arguments for this
    //return code_generator
    return nullptr;
}

ProgramElement::Ptr 
Operation::
search(Path search_path) const
{
    // XXX: stub
    return nullptr;
}

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
    return lhs.name < rhs.name;
}



} } //namespace fluster::db