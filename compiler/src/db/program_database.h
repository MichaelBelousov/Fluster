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



// forward declarations
struct Type; using TypePtr = util::Ptr<Type>;
struct Operation; using OperationPtr = util::Ptr<Operation>;
struct Variable; using VariablePtr = util::Ptr<Variable>;
struct ProgramElement; using ProgramElementPtr = util::Ptr<ProgramElement>;



// a pending dependency link that must be fulfilled
struct Reference
{
    const ProgramElementPtr Referer;
    const Path Reference;
};


struct UnresolvedReferences final : public std::exception
{
    std::vector<Reference> references;
};

struct MultipleDefinitions final : public std::exception
{
    //std::vector<ProgramElements>
};

struct NoSuchElement final : public std::exception
{
    const char* what() const noexcept final;
    Path element_path;
};


// TODO: rename to scope database?
struct ProgramDatabase
{
    //// Methods
    ProgramElementPtr search(Path path);

    // search without access constraints for debug purposes
    //ProgramElementPtr privilegedSearch(Path path);

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

    //// Members
    Table<Name, TypePtr> types;
    Table<Name, OperationPtr> operations;
    Table<Name, VariablePtr> variables;
    //Table<Name, Function::Ptr> functions;

private:
    std::vector<Reference> pending_references;  //list of unsatisfied references to resolve
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_DATABASE
