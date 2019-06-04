#ifndef FLUSTER_COMPILER_DB_PROGRAM_ELEMENT
#define FLUSTER_COMPILER_DB_PROGRAM_ELEMENT

#include <memory>
#include <utility>
#include <llvm/IR/Value.h>
#include "util/ptr.h"
#include "name.h"
#include "path.h"

/*
 * A ProgramElement is constructed by AST nodes and committed to a ProgramDatabase.
 * They are named, and some contain subelements in their own local databases.
 * They can return their llvm representation, being some existing symbol, a type,
 * or an operation.
 */

namespace fluster { namespace db {



// forward declaration
struct GenerationContext;



struct ProgramElement
    : public std::enable_shared_from_this<ProgramElement>
{
    //// Types
    using Ptr = util::Ptr<ProgramElement>;

    //// Methods
    template<typename ProgramElementChild, typename ...Args>
    ProgramElement::Ptr makeChildElement(Args&& ...args)
    {
        return ProgramElementChild::Ptr::make(std::forward<Args>(args)...);
    }
    virtual ProgramElement::Ptr search(Path search_path) const;
    virtual llvm::Value* getLLVMRepr( GenerationContext& ctx
                                    , const std::vector<llvm::Value*>& args
                                    ) const = 0;

    //// Members
    const Name name;
    const Path full_path;
    const ProgramElement::Ptr outer;

    //// Construction
    ProgramElement(const Name& in_name);
    virtual ~ProgramElement() = default;

protected:
    ProgramElement( const Name& in_name
                  , ProgramElement::Ptr in_outer
                  );
};



} } //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PROGRAM_ELEMENT
