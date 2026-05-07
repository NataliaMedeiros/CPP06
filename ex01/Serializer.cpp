#include " Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& original)
{
    *this = original;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    (void)rhs;
    return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

/*
reinterpret_cast - It is a low leval cast that reads the bits as another type.

here:
reinterpret_cast<uintptr_t>(ptr)
The compiler uses the poiter adress and uses it as integer

Example:
ptr = 0x12345678
becomes:
raw = 305419896
*/
