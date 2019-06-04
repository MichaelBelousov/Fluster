#include <vector>
#include <functional>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "type.h"
#include "program_element.h"

namespace fluster { namespace db {



//// Methods

llvm::Value*
Operation::
getLLVMRepr(GenerationContext& ctx, const std::vector<llvm::Value*>& args) const 
{
    return code_generator(args);
}

ProgramElement::Ptr 
Operation::
search(Path search_path) const
{
    if (Path::matchRoot(name, search_path))
        return shared_from_this();
    else
        throw(Path::NoSuchElement());
}

//// Construction

// TODO: use makeElement
Operation::
Operation( const Name& in_name
         , Type::Ptr in_return_type
         , const std::vector<Type::Ptr>& in_arg_types
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
