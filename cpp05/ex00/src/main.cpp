#include "../includes/Bureaucrat.hpp"

int main()
{
	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 1st Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 2 Bureaucrats and change grades\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("b2", 150);
		std::cout << b2 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 2nd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 2 Bureaucrats but one grade is too low\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("b2", 151);
		std::cout << b2 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 3rd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 2 Bureaucrats but one grade is too high\033[0m" << std::endl;
		Bureaucrat b1("b1", 150);
		std::cout << b1 << std::endl;
		Bureaucrat b2("b2", 0);
		std::cout << b2 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;

	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 4th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat and increment grade too much\033[0m" << std::endl;
		Bureaucrat b1("b1", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 5th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat and decrement grade too much\033[0m" << std::endl;
		Bureaucrat b1("b1", 149);
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		//b1.decrementGrade();
		//std::cout << b1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}