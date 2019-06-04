#ifndef FLUSTER_COMPILER_DB_PRIMITIVES
#define FLUSTER_COMPILER_DB_PRIMITIVES

#include <cstdint>
#include "type.h"
#include "context.h"
#include "program_database.h"

namespace fluster { namespace db {



/* Primitive types */

//metatype primitive
extern const Type::Ptr type_type

//integer primitive types
//extern static const Type::Ptr i8;
//extern static const Type::Ptr i16;
extern static const Type::Ptr i32;
//extern static const Type::Ptr i64;
//extern static const Type::Ptr Int;
//extern static const Type::Ptr APInt;

//unsigned integer primitive types
//extern static const Type::Ptr u8;
//extern static const Type::Ptr u16;
//extern static const Type::Ptr u32;
//extern static const Type::Ptr u64;
//extern static const Type::Ptr UInt;

//floating point primitive types
extern static const Type::Ptr f32;
//extern static const Type::Ptr f64;
//extern static const Type::Ptr Float;
//extern static const Type::Ptr APFloat;

//raw types
//extern static const Type::Ptr Bit;
//extern static const Type::Ptr Byte;
//extern static const Type::Ptr Word;

void commitPrimitives(ProgramDatabase& db, GenerationContext& ctx);



} }  //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PRIMITIVES
