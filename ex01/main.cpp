#include <iostream>
#include " Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;
	std::cout << "pre-serialized Value: " << data.value << std::endl;

    Data* originalPtr = &data;
    std::cout << "Original ptr:  " << originalPtr << std::endl;

    uintptr_t raw = Serializer::serialize(originalPtr);
	std::cout << "Value of our temp uintptr after serialization: " << raw << std::endl;

    Data* recoveredPtr = Serializer::deserialize(raw);
    std::cout << "Recovered ptr: " << recoveredPtr << std::endl;

    if (originalPtr == recoveredPtr)
        std::cout << "Pointers are equal!" << std::endl;

    std::cout << "Deserialized Value: " << recoveredPtr->value << std::endl;

    return 0;
}


