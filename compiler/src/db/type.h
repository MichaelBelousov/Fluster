#ifndef FLUSTER_COMPILER_DB_TYPE
#define FLUSTER_COMPILER_DB_TYPE

#include <memory>
#include <vector>
#include "program_element.h"
#include "program_database.h"
#include "util/ptr.h"

// TODO: use rtti for runtime type querying?
namespace fluster { namespace db {



struct Type
    : public ProgramElement
{
    //// Types
    using Ptr = util::Ptr<Type>;

    //// Methods
    //virtual Type::Ptr cloneof() const noexcept;
    //const Type::Ptr typeof() const noexcept override;
    //const bool is(Type::Ptr other) const noexcept;
    //const bool has(Type::Ptr other) const noexcept;
    llvm::Value* getLLVMRepr( GenerationContext& ctx
                            , const std::vector<llvm::Value*>& args
                            ) const final;
    ProgramElement::Ptr search(Path search_path) final;

    //static Type::Ptr makeInheritor() noexcept;
    //static Type::Ptr makeImplementor() noexcept;

    //// Construction
    Type( const Name& in_name );
    Type( const Name& in_name, bool in_is_final );
    Type( const Name& in_name
        , ProgramElement::Ptr in_outer
        , bool in_is_final
        );

    //// Methods
    ProgramDatabase db;

private:
    bool is_final;
    std::vector<Type::Ptr> children;
    Type::Ptr parent;
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_TYPE
