#ifndef FLUSTER_COMPILER_DB_PROGRAM_DATABASE
#define FLUSTER_COMPILER_DB_PROGRAM_DATABASE

#include <deque>
#include "util/ptr.h"
#include "db/table.h"
#include "db/program_element.h"
#include "name.h"

namespace fluster { namespace db {



// a pending dependency link that must be fulfilld
struct PendingReference
{
    const ProgramElement::Ptr Referee;
    const NamePath Reference;
};


struct ProgramDatabase
{
    //// Methods
    // finalize a program database
    ProgramElement::Ptr find(NamePath path)

    // search without access constraints for debug purposes
    ProgramElement::Ptr privilegedFind(NamePath path)

    // attempt to make sure all dependencies are satisfied
    void finalize() throw(MissingReferences);

private:
    // queue of unsatisfied dependencies to check for 
    std::vector<PendingReference> unsatisfied_dependency_list;
    Table<Name, Variable::Ptr> variables;
    Table<Name, Function::Ptr> functions;
    Table<Name, Type::Ptr> types;
    Table<Name, Operator::Ptr> operators;
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
