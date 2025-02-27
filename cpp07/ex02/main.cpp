#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;


	// My tests
	std::cout << "Testing default constructor:" << std::endl;
	Array<int> emptyArray;

	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
	try {
	    emptyArray[0] = 42;
	} catch (const std::exception &e) {
	    std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "Testing default initialization:" << std::endl;
	int *a = new int();
	std::cout << "Default initialized int: " << *a << std::endl;
	delete a;

	Array<int> defaultInitArray(5);
	for (unsigned int j = 0; j < defaultInitArray.size(); j++)
	    std::cout << "defaultInitArray[" << j << "]: " << defaultInitArray[j] << std::endl;

	std::cout << "Testing deep copy:" << std::endl;
	Array<int> original(4);
	original[0] = 10;
	original[1] = 20;
	original[2] = 30;	
	Array<int> copy(original);
	std::cout << "Original[0]: " << original[0] << " (should be 10)" << std::endl;
	std::cout << "Copy[0]: " << copy[0] << " (should be 10)" << std::endl;
	std::cout << "Original size: " << original.size() << std::endl;
	std::cout << "Copy size: " << copy.size() << std::endl;
	
	copy[0] = 100;
	original[0] = 1000;
	std::cout << "Testing modify deep copy:" << std::endl;
	std::cout << "Original[0]: " << original[0] << " (should be 1000)" << std::endl;
	std::cout << "Copy[0]: " << copy[0] << " (should be 100)" << std::endl;

	std::cout << "Testing assignment operator:" << std::endl;
	Array<int> assignTest(2);
	assignTest = copy;
	std::cout << "Copy[0]: " << copy[0] << " (should be 100)" << std::endl;
	std::cout << "assignTest[0]: " << assignTest[0] << " (should be 100)" << std::endl;
	std::cout << "Copy size: " << copy.size() << std::endl;
	std::cout << "assignTest size: " << assignTest.size() << std::endl;

	std::cout << "Testing modify assignment operator:" << std::endl;
	assignTest[0] = 200;
	std::cout << "Copy[0]: " << copy[0] << " (should be 100)" << std::endl;
	std::cout << "assignTest[0]: " << assignTest[0] << " (should be 200)" << std::endl;

	std::cout << "Testing out of range:" << std::endl;
	try {
		std::cout << original[4] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try {
		std::cout << original[-1] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "Testing const array (should not compile if assign value):" << std::endl;
	const Array<int> constArray(3);
	std::cout << "constArray[0]: " << constArray[0] << std::endl;
	try {
		//constArray[0] = 42;
		std::cout << "constArray[0]: " << constArray[0] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    return 0;
}