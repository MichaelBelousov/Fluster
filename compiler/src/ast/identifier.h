#ifndef FLUSTER_COMPILER_AST_IDENTIFIER
#define FLUSTER_COMPILER_AST_IDENTIFIER

#include <string>
#include "util/ptrs.h"
#include "expr.h"
#include "name.h"
#include "db/type.h"

namespace fluster { namespace ast {



struct Identifier final
    : public Expr
{
    //// Construction
    Identifier(const std::string& in_name);

    //// Overridden Methods
    void commit(db::ProgramDatabase& db) const override;
    llvm::Value* generateCode(GenerationContext& ctx) const override;
    void print(std::ostream& os, unsigned indent_level) const override;

    //// Types
    using Ptr = util::Ptr<Identifier>;

private:
    //// Members
    const Name name;
};



} }

#endif //FLUSTER_COMPILER_AST_IDENTIFIER
