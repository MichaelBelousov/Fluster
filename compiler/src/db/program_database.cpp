#include "program_database.h"
#include <utility>
#include "operation.h"
#include "variable.h"
#include "type.h"

namespace fluster { namespace db {



//// NoSuchElement

const char*
NoSuchElement::
what() const noexcept
{
    return "element not found";
}

//// Methods

ProgramElement::Ptr 
ProgramDatabase::
search(Path search_path)
{
    // TODO: is search_path empty? It shouldn't be possible, no?
    auto name = search_path[0];

    auto type_found = types.find(name);
    if (type_found != types.end())
        return type_found->second->search(search_path.next());

    auto op_found = operations.find(name);
    if (op_found != operations.end())
        return op_found->second->search(search_path.next());

    auto var_found = variables.find(name);
    if (var_found != variables.end())
        return var_found->second->search(search_path.next());

    throw NoSuchElement();
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
