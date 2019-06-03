#include "context.h"

namespace fluster {



GenerationContext::
GenerationContext()
    : context()
    , builder(llvm_context)
    , module()
    , db()
{}

static GenerationContext the_context();



}  //namespace fluster
