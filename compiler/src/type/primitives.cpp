#include "primitives.h"
#include "type.h"

namespace fluster {



/* Primitive types */

const TypePtr TheType(new Type);

//integer primitive types
const TypePtr int8(new Type);
const TypePtr int16(new Type);
const TypePtr int32(new Type);
const TypePtr int64(new Type);
const TypePtr& int_ = int32;
//unsigned integer primitive types
const TypePtr uint8(new Type);
const TypePtr uint16(new Type);
const TypePtr uint32(new Type);
const TypePtr uint64(new Type);
const TypePtr& uint = uint32;

//floating point primitive types
const TypePtr float32(new Type);
const TypePtr float64(new Type);
const TypePtr& float_ = float32;

//raw types
const TypePtr bit(new Type);
const TypePtr byte(new Type);
const TypePtr word(new Type);



};
