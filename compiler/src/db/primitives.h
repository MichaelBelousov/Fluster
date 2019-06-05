#ifndef FLUSTER_COMPILER_DB_PRIMITIVES
#define FLUSTER_COMPILER_DB_PRIMITIVES

#include <cstdint>
#include "type.h"
#include "context.h"
#include "program_database.h"

namespace fluster { namespace db {



/* Primitive types */

//metatype primitive
extern const Type::Ptr type_type;

//integer primitive types
//extern const Type::Ptr i8;
//extern const Type::Ptr i16;
extern const Type::Ptr i32;
//extern const Type::Ptr i64;
//extern const Type::Ptr Int;
//extern const Type::Ptr APInt;

//unsigned integer primitive types
//extern const Type::Ptr u8;
//extern const Type::Ptr u16;
//extern const Type::Ptr u32;
//extern const Type::Ptr u64;
//extern const Type::Ptr UInt;

//floating point primitive types
extern const Type::Ptr f32;
//extern const Type::Ptr f64;
//extern const Type::Ptr Float;
//extern const Type::Ptr APFloat;

//raw types
//extern const Type::Ptr Bit;
//extern const Type::Ptr Byte;
//extern const Type::Ptr Word;

void commitPrimitives(ProgramDatabase& db, GenerationContext& ctx);



} }  //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PRIMITIVES
