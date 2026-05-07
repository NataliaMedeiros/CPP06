#pragma once
/* pragma once is a header guard shortcut used in C and C++ header files
	to prevent the same file from being included multiple times during
	compilation. Use it instead of #ifndef #define #endif*/

	// #ifndef  SERIALIZER_HPP
// #define  SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include "data.hpp"

class  Serializer
{
	private:
	/*The constructor are private because the subjects says:
	Serializer class will not be initializable by the user*/
		Serializer();
		Serializer(const Serializer& original);
		Serializer& operator=(const Serializer& rhs);
		~Serializer();

		public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

/*uintptr_t é um tipo inteiro sem sinal capaz de armazenar
	um endereço de memória.*/

// #endif
