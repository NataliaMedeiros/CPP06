#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter(){}

bool	isChar(const std::string& s)
{
	if (s.length() == 1 && !std::isdigit(s[0]))
		return (true);
	// Optionally handle quotes: 'a'
	if (s.size() == 3 && s.front() == '\'' && s.back() == '\'' && std::isprint(s[1]))
		return (true);
	return (false);
}

bool	isInt(const std::string& s)
{
	if (s.empty())
		return false;
	size_t start = 0;
	if (s[0] == '+' || s[0] == '-')
		start = 1;
	if (start == s.size())
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
	// Handle pseudo-literals
	size_t i = 0;
	bool hasDigits = false;
	bool hasDot = false;
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return true;
	if (s.empty())
		return false;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (; i < s.size(); ++i)
	{
		if (std::isdigit(s[i]))
		{
			hasDigits = true;
			continue;
		}
		else if (s[i] == '.' && !hasDot)
			hasDot = true;
		else if (s[i] == 'f' && i == s.size() - 1 && hasDot && hasDigits)
			return true;
		else
			return false;
	}
	return (false);
}

bool	isDouble(const std::string& s)
{
	size_t i = 0;
	bool hasDigits = false;
	bool hasDot = false;
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;
	if (s.empty())
		return false;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (; i < s.size(); ++i)
	{
		if (std::isdigit(s[i]))
		{
			hasDigits = true;
			continue;
		}
		else if (s[i] == '.' && !hasDot)
			hasDot = true;
		else
			return false;
	}
	return hasDigits && hasDot;
}

int	detectType(const std::string& input)
{
	const std::string	types[] = {"char", "int", "float", "double"};
	bool	(*function[])(const std::string&)= {&isChar, &isInt, &isFloat, &isDouble};
	if (input.empty())
	{
		std::cout << "Input cannot be Empty, please try again" << std::endl;
		return (-1);
	}
	for (int i = 0; i < 4; i++)
	{
		if(function[i](input) == true)
		{
			return (i);
		}
	}
	return (-1);
}

double	findValue(const std::string& input, int type)
{
	double value = 0.0;
	switch (type)
	{
		case 0: // char
			value = input[0];
			break;
		case 1: // int
			// value = std::atoi(input.c_str());
			value = std::strtol(input.c_str(), NULL, 10);
			break;
		case 2: // float
			value = std::strtof(input.c_str(), NULL);
			break;
		case 3: // double
			value = std::strtod(input.c_str(), NULL);
			break;
	}
	return (value);
}

void	printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

void	printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

void	printFloat(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: ";
	std::cout << static_cast<float>(value) << "f" << std::endl;
}

void	printDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: ";
	std::cout << value << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	int	type;
	type = detectType(input);
	if (type == -1)
	{
		std::cout << "Invalid literal\n";
		return ;
	}
	double	value = findValue(input, type);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
