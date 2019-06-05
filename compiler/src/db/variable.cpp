#include "variable.h"
#include "type.h"

namespace fluster { namespace db {



//// Methods

llvm::Value*
Variable::
getLLVMRepr(GenerationContext& ctx, const std::vector<llvm::Value*>& _) const 
{
    return llvm_value;
}

ProgramElement::Ptr 
Variable::
search(Path search_path)
{
    if (search_path == name)
        return shared_from_this();
    else
        return type->db.search(search_path.next());
}

//// Construction

Variable::
Variable(const Name& in_name, Type::Ptr in_type, llvm::Value*const in_llvm_value)
    : ProgramElement(name)
    , type(in_type)
    , llvm_value(in_llvm_value)
{}

//// Operations

bool operator< (const Variable& lhs, const Variable& rhs)
{
    return lhs.name < rhs.name;
}



} } //namespace fluster::db
