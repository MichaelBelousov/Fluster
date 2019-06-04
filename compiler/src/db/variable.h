#ifndef FLUSTER_COMPILER_DB_VARIABLE
#define FLUSTER_COMPILER_DB_VARIABLE

#include <vector>
#include "util/ptr.h"
#include "program_element.h"

namespace fluster { namespace db {



struct Type; using TypePtr = util::Ptr<Type>;



struct Variable
    : public ProgramElement
{
    //// Types
    using Ptr = util::Ptr<Variable>;

    //// Methods
    llvm::Value* getLLVMRepr( GenerationContext& ctx
                            , const std::vector<llvm::Value*>& args
                            ) const final;
    ProgramElement::Ptr search(Path search_path) const final;

    //// Construction
    Variable(const Name& in_name, TypePtr in_type, const llvm::Value* in_llvm_value);

    //// Operations
    friend bool operator< (const Variable& lhs, const Variable& rhs);

private:
    //// Members
    const TypePtr type;
    const llvm::Value*const llvm_value;
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_VARIABLE
