#include "variable.h"
#include <functional>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "program_element.h"

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

Variable(const Name& in_name)
    : ProgramElement(name)
{}

//// Operations

friend bool operator< (const Variable& lhs, const Variable& rhs)
{
    return lhs.name < rhs.name;
}



} } //namespace fluster::db
