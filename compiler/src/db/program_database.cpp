#include "program_database.h"
#include "operation.h"

namespace fluster { namespace db {



//// Methods

ProgramElement::Ptr 
ProgramDatabase::
search(Path path)
{
    // XXX: this is a stub!
    // should actually throw on failure
    return nullptr;
}


void
ProgramDatabase::
addOperation(const Name& name, Operation::Ptr operation)
{
    // TODO: perform std::find check to see if that operation is already
    // there, if it is, then throw a multiple definition warning and take the
    // latter

    //check if there are any pending references to this name, compare types, and resolve or throw
    operations[name] = operation;
}


void
ProgramDatabase::
finalize()
{
    //if there are any unresolved references still, throw
}



} } //namespace fluster::db
