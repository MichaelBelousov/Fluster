#ifndef FLUSTER_COMPILER_AST_NODE_TIMPL
#define FLUSTER_COMPILER_AST_NODE_TIMPL

#include <array>
#include <string>
#include <vector>
#include "util/ptr.h"

namespace fluster { namespace ast {



template<typename T, typename ...Args>
Node::Ptr
Node::
makeChildNode(Args&& ...args)
{
    Node::Ptr result = new T(std::forward<Args>(args)...);
    const_cast<WeakPtr<Node>&>(result->outer) =
        this->shared_from_this();
    return result;
}

template<typename T, typename ...Args>
Node::Ptr
Node::
makeParentNode(Args&& ...args)
{
    Node::Ptr result = new T(std::forward<Args>(args)...);
    const_cast<WeakPtr<Node>&>(this->outer) =
        result->shared_from_this();
    return result;
}



} }

#endif //FLUSTER_COMPILER_AST_NODE_TIMPL
