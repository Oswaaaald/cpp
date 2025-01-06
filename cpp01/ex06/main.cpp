#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string level;

	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (1);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}