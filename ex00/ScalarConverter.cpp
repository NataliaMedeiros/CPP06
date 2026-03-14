#include "ScalarConverter.hpp"

		// ScalarConverter(/* args */);
		// ScalarConverter(const ScalarConverter& original);
		// ScalarConverter& operator=(const ScalarConverter& rhs);
		// ~ScalarConverter();

bool	isChar(const std::string& s)
{
	// std::cout << s.size();
	// std::cout << s[0] << std::endl;
	if (s.size() == 1 && std::isalpha(s[0]))
		return (true);

    // Optionally handle quotes: 'a'
	if (s.size() == 3 && s.front() == '\'' && s.back() == '\'' && std::isprint(s[1]))
		return (true);

	return (false);
}
bool	isInt(const std::string& s)
{
	// std::cout << "int";
	if (s.empty())
		return false;
	size_t start = 0;
	if (s[0] == '+' || s[0] == '-')  // handle optional sign
		start = 1;
	if (start == s.size()) // string is just "+" or "-"
		return false;
	for (size_t i = start; i < s.size(); ++i)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}
bool	isFloat(const std::string& s)
{
	// std::cout << "float";
	// Handle pseudo-literals
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;
	size_t i = 0;
	if (s.empty())
		return false;
	// Optional sign
	if (s[i] == '+' || s[i] == '-')
		++i;
	bool hasDigits = false;
	bool hasDot = false;
	// Parse digits and decimal point
	for (; i < s.size(); ++i)
	{
		if (std::isdigit(s[i]))
		{
			hasDigits = true;
			continue;
		}
		else if (s[i] == '.' && !hasDot)
		{
			hasDot = true;
		}
		else if (s[i] == 'f' && i == s.size() - 1 && hasDot && hasDigits)
		{
			return true;
		}
		else
		{
			return false; // invalid character
		}
	}

	return (false);
}

bool	isDouble(const std::string& s)
{
	// std::cout << "double";
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;
	size_t i = 0;
	if (s.empty())
		return false;

	// Optional sign
	if (s[i] == '+' || s[i] == '-')
		++i;

	bool hasDigits = false;
	bool hasDot = false;

	// Parse digits and decimal point
	for (; i < s.size(); ++i)
	{
		if (std::isdigit(s[i]))
		{
			hasDigits = true;
			continue;
		}
		else if (s[i] == '.' && !hasDot)
		{
			hasDot = true;
		}
		else
		{
			return false; // invalid character
		}
	}

    // Must have at least one digit and one dot
	return hasDigits && hasDot;
}

void ScalarConverter::convert(const std::string& input)
{
	std::string	type;
	const std::string	types[] = {"char", "int", "float", "double"};
	bool	(*function[])(const std::string&)= {&isChar, &isInt, &isFloat, &isDouble};
	if (input.empty())
	{
		std::cout << "Input cannot be Empty, please try again" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if(function[i](input) == true)
		{
			type = types[i];
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (type == types[i])
		{
			std::cout << types[i];
		}
	}
}
