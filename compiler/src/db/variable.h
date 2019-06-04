#ifndef FLUSTER_COMPILER_DB_VARIABLE
#define FLUSTER_COMPILER_DB_VARIABLE

#include <vector>
#include <functional>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "db/program_element.h"

namespace fluster { namespace db {



struct Type;
using TypePtr = util::Ptr<Type>;

//TODO: inherit from callable/invokable ProgramElement

struct Variable
    : public ProgramElement
{
    //// Types
    using Ptr = util::Ptr<Variable>;

    //// Methods
    llvm::Value* getLLVMRepr(GenerationContext& ctx) const final;

    ProgramElement::Ptr search(Path search_path) const final;

    //// Construction
    Variable(const Name& in_name);

    //// Operations
    friend bool operator< (const Variable& lhs, const Variable& rhs);
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_VARIABLE
