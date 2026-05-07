#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter
{
	/* These should be private because the subjecte says:
		"As this class doesn’t need to store anything at all,
		it must not be instantiable by users."*/
	private:
		ScalarConverter(/* args */);
		ScalarConverter(const ScalarConverter& original);
		ScalarConverter& operator=(const ScalarConverter& rhs);

	public:
		~ScalarConverter();
		static void convert(const std::string& input);
};

#endif
