#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void convertChar(double value) {
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void convertInt(double value) {
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() || std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void convertFloat(double value) {
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void convertDouble(double value) {
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") <<std::endl;
	else if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

int	isChar(const std::string &str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return 1;
	return 0;
}

int isInt(const std::string &str)
{
	char *endptr;
	std::strtol(str.c_str(), &endptr, 10);
	if (*endptr == '\0')
		return 1;
	return 0;
}

int isFloat(const std::string &str)
{
	char *endptr;
	std::strtof(str.c_str(), &endptr);
	if ((*(endptr + 1) == '\0' && *endptr == 'f') && ((*(endptr - 1) != '.') && (*(endptr - 1) != 'f')))
		return 1;
	return 0;
}

int isDouble(const std::string &str)
{
	char *endptr;
	std::strtod(str.c_str(), &endptr);
	if (*endptr == '\0')
		return 1;
	return 0;
}

void ScalarConverter::convert(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	double doubleValue;
	char charValue;
	long long int intValue;
	float floatValue;
	char *endptr;
	if (isChar(str))
	{
		charValue = str[0];
		//std::cout << "CHAR" << std::endl;
		doubleValue = static_cast<double>(charValue);
	}
	else if (isInt(str))
	{
		intValue = std::strtoll(str.c_str(), &endptr, 10);

		if (intValue > std::numeric_limits<int>::max() || intValue < std::numeric_limits<int>::min())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}

		//std::cout << "INT" << std::endl;
		doubleValue = static_cast<double>(intValue);
	}
	else if (isDouble(str))
	{
		doubleValue = std::strtod(str.c_str(), &endptr);
		//std::cout << "DOUBLE" << std::endl;
	}
	else if (isFloat(str))
	{
		floatValue = std::strtof(str.c_str(), &endptr);
		//std::cout << "FLOAT" << std::endl;
		doubleValue = static_cast<double>(floatValue);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	convertChar(doubleValue);
	convertInt(doubleValue);
	convertFloat(doubleValue);
	convertDouble(doubleValue);
}