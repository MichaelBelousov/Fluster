#include <string>
#include <regex>
#include "identifier.h"
#include "db/variable.h"
#include "context.h"

namespace fluster { namespace ast {



//// Methods

void
Identifier::
commit(db::ProgramDatabase& db) const
{
    //auto var = Variable::Ptr::make(name, )
    //db.addVariable(var)
}

llvm::Value*
Identifier::
generateCode(GenerationContext& ctx) const
{
    // TODO: need to catch and throw no such name exceptions if not there
    return result_type->db.variables[name]->getLLVMRepr(ctx);
}

void
Identifier::
print(std::ostream& os, unsigned indent_level) const
{
    for (unsigned i = 0; i < indent_level; ++i) os << " ";
    os << "<identifier name=\"" << name << "\" />" << std::endl;
}

//// Construction

Identifier::
Identifier(const std::string& in_name)
    : name(in_name)
{}



} }
