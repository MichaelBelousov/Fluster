#include "context.h"

namespace fluster {



GenerationContext::
GenerationContext()
    : context()
    , builder(llvm_context)
    , module()
    , db()
{}


GenerationContext the_context();



}  //namespace fluster
