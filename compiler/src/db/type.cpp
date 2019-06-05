#include "type.h"

namespace fluster { namespace db {


//// Methods


llvm::Value*
Type::
getLLVMRepr(GenerationContext& ctx, const std::vector<llvm::Value*>& _) const 
{
    // XXX: need to figure out if types will have llvm representation
    return nullptr;
}

ProgramElement::Ptr
Type::
search(Path search_path) const
{
    if (search_path == name)
        return shared_from_this();
    else
        return db.search(search_path.next());
}

/*
//return a clone
TypePtr Type::cloneof() const {
    return Type(*this);
}

//return the type of types, TheType
const TypePtr Type::typeof() const override {
    return TheType;
}
*/

//// Construction

Type::
Type( const Name& in_name )
    : ProgramElement(in_name)
    , db()
    , is_final(false)
{}

Type::
Type( const Name& in_name, bool in_is_final )
    : ProgramElement(in_name)
    , db()
    , is_final(in_is_final)
{}

Type::
Type( const Name& in_name
    , ProgramElement::Ptr in_outer
    , bool in_is_final
    )
    : ProgramElement(in_name, in_outer)
    , db()
    , is_final(in_is_final)
{}



} } //namespace fluster::db
