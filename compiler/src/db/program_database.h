#ifndef FLUSTER_COMPILER_DB_PROGRAM_DATABASE
#define FLUSTER_COMPILER_DB_PROGRAM_DATABASE

#include <deque>
#include <exception>
#include "util/ptr.h"
#include "table.h"
#include "program_element.h"
#include "operation.h"
#include "name.h"
#include "path.h"

namespace fluster { namespace db {



// FIXME: ugly forward decleration needs to be done better
struct Type;
using TypePtr = util::Ptr<Type>;
struct Operatoin;
using OperationPtr = util::Ptr<Type>;

// a pending dependency link that must be fulfilled
struct Reference
{
    const ProgramElement::Ptr Referee;
    const Path Reference;
};


struct UnresolvedReferences : public std::exception
{
    std::vector<Reference> references;
};

struct MultipleDefinitions : public std::exception
{
    //std::vector<ProgramElements>
};


struct ProgramDatabase
{
    //// Methods
    ProgramElement::Ptr search(Path path);

    // search without access constraints for debug purposes
    //ProgramElement::Ptr privilegedSearch(Path path);

    // add names
    //void addVariable(const Name& name, Variable::Ptr variable);
    //void addFunction(const Name& name, Function::Ptr function);
    //void addType(const Name& name, TypePtr type);

    /* @throws MultipleDefinitions */
    void addOperation(const Name& name, OperationPtr operation);

    // attempt to make sure all dependencies are satisfied
    // should return Consistent or Complete >ProgramDatabase
    // or just use a builder pattern
    /* @throws UnresolvedReferences */
    void finalize();

    //// Construction
    ProgramDatabase() = default;
    ProgramDatabase(ProgramDatabase&&) = default;

private:
    // list of unsatisfied references to resolve
    std::vector<Reference> pending_references;

    //Table<Name, Variable::Ptr> variables;
    //Table<Name, Function::Ptr> functions;
    Table<Name, TypePtr> types;
    Table<Name, OperationPtr> operations;
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
