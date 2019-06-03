#ifndef FLUSTER_COMPILER_DB_PROGRAM_ELEMENT
#define FLUSTER_COMPILER_DB_PROGRAM_ELEMENT

#include <memory>
#include "util/ptr.h"
#include "name.h"
#include "path.h"

namespace fluster { namespace db {



struct ProgramElement
    : public std::enable_shared_from_this<ProgramElement>
{
    //// Types
    using Ptr = util::Ptr<ProgramElement>;

    //// Methods
    ProgramElement::Ptr makeChildElement(const Name& in_name);
    virtual ProgramElement::Ptr search(Path search_path);

    //// Members
    const Name name;
    const Path full_path;
    const ProgramElement::Ptr outer;

    //// Construction
    ProgramElement(const Name& in_name);

protected:
    ProgramElement( const Name& in_name
                  , ProgramElement::Ptr in_outer
                  );
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_ELEMENT
