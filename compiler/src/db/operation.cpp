#include <vector>
#include <functional>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "type.h"
#include "program_element.h"
#include "program_database.h"

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
search(Path search_path)
{
    if (search_path == name)
        return shared_from_this();
    else
        throw NoSuchElement();
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
    , arg_types(in_arg_types)
    , code_generator(in_code_generator)
{}

//// Operations

bool operator< (const Operation& lhs, const Operation& rhs)
{
    return lhs.name < rhs.name;
}



} } //namespace fluster::db
