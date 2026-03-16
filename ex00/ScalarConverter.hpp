#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string.h>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
	public:
		ScalarConverter(/* args */);
		ScalarConverter(const ScalarConverter& original);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();

		static void convert(const std::string& input);
};

#endif
