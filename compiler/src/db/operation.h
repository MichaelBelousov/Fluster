#ifndef FLUSTER_COMPILER_DB_OPERATION
#define FLUSTER_COMPILER_DB_OPERATION

#include <vector>
#include <functional>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "db/program_element.h"

namespace fluster { namespace db {



struct Type;
using TypePtr = util::Ptr<Type>;

//TODO: inherit from callable/invokable ProgramElement

using CallableImpl = llvm::Value*(std::vector<llvm::Value*>&);

struct Operation
    : public ProgramElement
{
    //// Types
    using Ptr = util::Ptr<Operation>;

    //// Members
    TypePtr return_type;
    std::vector<TypePtr> arg_types;
    std::function<CallableImpl> code_generator;

    //// Construction
    Operation( const Name& in_name
             , TypePtr in_return_type
             , const std::vector<TypePtr>& in_arg_types
             , const std::function<CallableImpl>& in_code_generator
             );

    //// Operations
    friend bool operator< (const Operation& lhs, const Operation& rhs);
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_OPERATION
