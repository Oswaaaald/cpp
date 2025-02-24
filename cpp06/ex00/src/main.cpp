#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	std::string arg = argv[1];
	if (arg == "-exception")
	{
		std::cout << "Test nanf" << std::endl;
		ScalarConverter::convert("nanf");
		std::cout << "Test inf" << std::endl;
		ScalarConverter::convert("inf");
		std::cout << "Test +inf" << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << "Test -inf" << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << "Test 0" << std::endl;
		ScalarConverter::convert("0");
		std::cout << "Test 0.0" << std::endl;
		ScalarConverter::convert("0.0");
		std::cout << "Test *" << std::endl;
		ScalarConverter::convert("*");
		std::cout << "Test **" << std::endl;
		ScalarConverter::convert("**");
		std::cout << "Test 2147483648" << std::endl;
		ScalarConverter::convert("2147483648");
		std::cout << "Test -2147483649" << std::endl;
		ScalarConverter::convert("-2147483649");
		std::cout << "Test 2147483648.0" << std::endl;
		ScalarConverter::convert("2147483648.0");
		std::cout << "Test -2147483649.0" << std::endl;
		ScalarConverter::convert("-2147483649.0");
		std::cout << "Test 2147483648.0f" << std::endl;
		ScalarConverter::convert("2147483648.0f");
		std::cout << "Test -2147483649.0f" << std::endl;
		ScalarConverter::convert("-2147483649.0f");
	}
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}