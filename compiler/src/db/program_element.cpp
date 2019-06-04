#include "program_element.h"
#include "path.h"

namespace fluster { namespace db {



//// Methods


ProgramElement::Ptr
ProgramElement::
search(Path search_path) const
{
    // XXX: stub, needs
    return ProgramElement::Ptr::make();
}


//// Construction


ProgramElement::
ProgramElement(const Name& in_name)
    : name(in_name)
    , full_path({name})
    , outer()
{}


ProgramElement::
ProgramElement( const Name& in_name
              , ProgramElement::Ptr in_outer
              )
    : name(in_name)
    , full_path(outer->full_path + Path{in_name})
    , outer(in_outer)
{}



} } //namespace fluster::db
