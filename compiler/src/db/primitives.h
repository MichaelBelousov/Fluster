#ifndef FLUSTER_COMPILER_DB_PRIMITIVES
#define FLUSTER_COMPILER_DB_PRIMITIVES

#include <cstdint>
#include "type.h"

namespace fluster { namespace db {



/* Primitive types */

//metatype primitive
extern const Type::Ptr type_type

//integer primitive types
extern static const Type::Ptr i8;
extern static const Type::Ptr i16;
extern static const Type::Ptr i32;
extern static const Type::Ptr i64;
extern static const Type::Ptr Int;
extern static const Type::Ptr APInt;

//unsigned integer primitive types
extern static const Type::Ptr u8;
extern static const Type::Ptr u16;
extern static const Type::Ptr u32;
extern static const Type::Ptr u64;
extern static const Type::Ptr UInt;

//floating point primitive types
extern static const Type::Ptr f32;
extern static const Type::Ptr f64;
extern static const Type::Ptr Float;
extern static const Type::Ptr APFloat;

//raw types
extern static const Type::Ptr Bit;
extern static const Type::Ptr Byte;
extern static const Type::Ptr Word;


//TODO: std::enable_if<std::is_scalar<CppAnalogType>>::value>
template<typename CppAnalogType>
class PrimitiveValue final : public BaseValue{
    CppAnalogType payload;
    const Type::Ptr typeof() const noexcept final;
};

#define DEF_PRIMITIVE(ctype, real)      \
const Type::Ptr                         \
PrimitiveValue<(ctype)>::               \
typeof() const final noexcept           \
{                                       \
    return (real);                      \
}

DEF_PRIMITIVE(std::int8_t, i8)
DEF_PRIMITIVE(std::int16_t, i16)
DEF_PRIMITIVE(std::int32_t, i32)
DEF_PRIMITIVE(std::int64_t, i64)

DEF_PRIMITIVE(std::uint8_t, u8)
DEF_PRIMITIVE(std::uint16_t, u16)
DEF_PRIMITIVE(std::uint32_t, u32)
DEF_PRIMITIVE(std::uint64_t, u64)



} }  //namespace fluster::db

#endif //FLUSTER_COMPILER_DB_PRIMITIVES
