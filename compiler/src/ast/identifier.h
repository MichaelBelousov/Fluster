#ifndef FLUSTER_COMPILER_AST_IDENTIFIER
#define FLUSTER_COMPILER_AST_IDENTIFIER

#include <string>
#include <memory>
#include <regex>
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
    const bool
    isValidName(const std::string& in);
};


struct Identifier final
    : public Expr
{
private:
    //// Members

    const Name name;

public:
    //// Types

    using Ptr = std::shared_ptr<Identifier>;

    //// Construction

    Identifier(const std::string& in_name);

    //// Methods

    const data::Construct::Ptr finalize() const override;
};



}; };

#endif //FLUSTER_COMPILER_AST_IDENTIFIER
