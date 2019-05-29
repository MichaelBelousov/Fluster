#ifndef FLUSTER_COMPILER_AST_IDENTIFIER
#define FLUSTER_COMPILER_AST_IDENTIFIER

/* The fluster data holds immutable, finalized versions
 * of each fluster construct, in a code base, after they
 * have been parsed, and its usage has been semantically validated
 */

#include <string>
#include <memory>
#include "expr.h"

namespace fluster { namespace ast {



struct Name final
{
    Name(const std::string& in_value);

    const std::string value;

    static
    const bool
    validate(const std::string& in);
};


struct Identifier final
    : public Expr
{
    const Name name;

    const data::Construct::Ptr finalize() const override;
};



}; };

#endif //FLUSTER_COMPILER_AST_IDENTIFIER
