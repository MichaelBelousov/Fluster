#include "context.h"

namespace fluster {



GenerationContext::
GenerationContext()
    : context()
    , builder(context)
    , module()
    , db()
{}


GenerationContext the_context();



}  //namespace fluster
