#include "easyfind.hpp"

int	main(void)
{
	// Test Vector
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try
	{
		std::vector<int>::iterator it;
		it = easyfind(vec, 5);
		std::cout << "Element found: " << *it << std::endl;
		it = easyfind(vec, 0);
		std::cout << "Element found: " << *it << std::endl;
		it = easyfind(vec, 10);
		std::cout << "Element found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test List
	std::list<int> lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	try
	{
		std::list<int>::iterator it;
		it = easyfind(lst, 5);
		std::cout << "Element found: " << *it << std::endl;
		it = easyfind(lst, 0);
		std::cout << "Element found: " << *it << std::endl;
		it = easyfind(lst, 10);
		std::cout << "Element found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}