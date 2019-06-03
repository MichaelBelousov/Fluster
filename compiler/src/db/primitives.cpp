#include "primitives.h"
#include "type.h"

namespace fluster { namespace db {



/* Primitive types */

static const Type::Ptr TheType(new Type);

//integer primitive types
const Type::Ptr i8(new Type);
const Type::Ptr i16(new Type);
const Type::Ptr i32(new Type);
const Type::Ptr i64(new Type);
const Type::Ptr Int(new Type);
const Type::Ptr APInt(new Type);

//unsigned integer primitive types
const Type::Ptr u8(new Type);
const Type::Ptr u16(new Type);
const Type::Ptr u32(new Type);
const Type::Ptr u64(new Type);
const Type::Ptr UInt(new Type);

//floating point primitive types
const Type::Ptr f32(new Type);
const Type::Ptr f64(new Type);
const Type::Ptr Float(new Type);
const Type::Ptr APFloat(new Type);

//raw types
const Type::Ptr Bit(new Type);
const Type::Ptr Byte(new Type);
const Type::Ptr Word(new Type);



} }  //namespace fluster::db
