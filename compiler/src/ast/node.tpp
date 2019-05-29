#ifndef FLUSTER_COMPILER_AST_NODE_TIMPL
#define FLUSTER_COMPILER_AST_NODE_TIMPL

#include <array>
#include <string>
#include <vector>
#include <memory>
#include "util.h"

namespace fluster { namespace ast {



template<typename T, typename ...Args>
Node::Ptr
Node::
makeChild(Args&& ...args)
{
    Node::Ptr result = new T(std::forward<Args>(args)...);
    const_cast<Node::Ptr>(result.outer) = this->shared_from_this();
    return result;
}



}; };

#endif //FLUSTER_COMPILER_AST_NODE_TIMPL
