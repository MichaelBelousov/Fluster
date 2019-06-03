#include "type.h"

namespace fluster { namespace db {


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

//// Methods

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



} } //namespace fluster::db
