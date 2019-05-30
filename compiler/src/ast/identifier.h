#ifndef FLUSTER_COMPILER_AST_IDENTIFIER
#define FLUSTER_COMPILER_AST_IDENTIFIER

#include <string>
#include <regex>
#include "util/ptr.h"
#include "expr.h"

namespace fluster { namespace ast {



struct Name final
{
private:
    //// Constants
    static
    const std::regex valid_pattern;

    //// Members
    const std::string value;

public:
    //// Construction
    Name(const std::string& in_value);

    //// Methods
    static
    bool
    isValidName(const std::string& in);
};


struct Identifier final
    : public Expr
{
    //// Construction
    Identifier(const std::string& in_name);

    //// Methods
    //const data::Construct::Ptr finalize() const override;

    //// Types
    using Ptr = util::Ptr<Identifier>;

private:
    //// Members
    const Name name;
};



} }

#endif //FLUSTER_COMPILER_AST_IDENTIFIER
