#include <string>
#include <regex>
#include "identifier.h"
#include "db/variable.h"
#include "context.h"

namespace fluster { namespace ast {



//// Construction

Identifier::
Identifier(const std::string& in_name)
    : name(in_name)
{}

//// Methods
    
llvm::Value*
Identifier::
generateCode(GenerationContext& ctx) const
{
    // TODO: need to catch and throw no such name exceptions
    return result_type->db.variables[name]->getLLVMRepr(ctx);
}



} }
