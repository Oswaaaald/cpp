#include "iter.hpp"

int main(void)
{
	int array[] = {0, 1, 2, 3, 4, 5};
	std::cout << "printValue:" << std::endl;
	iter(array, 6, printValue);
	std::cout << "addTen:" << std::endl;
	iter(array, 6, addTen);
	std::cout << "remFive:" << std::endl;
	iter(array, 6, remFive);
	std::cout << "remFive:" << std::endl;
	iter(array, 6, remFive);

	char array2[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	std::cout << "printValue:" << std::endl;
	iter(array2, 6, printValue);
	std::cout << "addTen:" << std::endl;
	iter(array2, 6, addTen);
	std::cout << "remFive:" << std::endl;
	iter(array2, 6, remFive);
	std::cout << "remFive:" << std::endl;
	iter(array2, 6, remFive);

	return 0;
}