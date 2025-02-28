#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// My tests
	try {
		Span sp2 = Span(20000);
		int arr[20000];

		for (int i = 0; i < 10000; i++)
			arr[i] = i;
		for (int i = 10000; i < 20000; i++)
			arr[i] = 20000 - i;
		arr[20] = 1500000;

		sp2.addFullNumbers(arr, arr + 20000);

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Span sp3 = Span(1);

		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Span sp4 = Span(4);

		sp4.addNumber(6);
		sp4.addNumber(3);
		sp4.addNumber(17);
		sp4.addNumber(9);
		sp4.addNumber(11);

		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}