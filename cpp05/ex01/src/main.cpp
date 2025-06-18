#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 1st Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat make him sign\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Form f1("f1", 3, 2);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 2nd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrats, make him sign twice\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("b2", 1);
		std::cout << b2 << std::endl;
		Form f1("f1", 1, 1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.signForm(f1);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 3rd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 2 Bureaucrats, make them sign the same form\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("b2", 1);
		std::cout << b2 << std::endl;
		Form f1("f1", 1, 1);
		std::cout << f1 << std::endl;
		b2.signForm(f1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 4th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat, make him sign a form with grade too low\033[0m" << std::endl;
		Bureaucrat b1("b1", 2);
		std::cout << b1 << std::endl;
		Form f1("f1", 1, 1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 5th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat, make him sign a form with grade too low, increment then sign\033[0m" << std::endl;
		Bureaucrat b1("b1", 2);
		std::cout << b1 << std::endl;
		Form f1("f1", 1, 1);
		std::cout << f1 << std::endl;
		//b1.signForm(f1);
		//std::cout << f1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 6th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat, make him sign 2 different forms twice\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Form f1("f1", 1, 1);
		std::cout << f1 << std::endl;
		Form f2("f2", 1, 1);
		std::cout << f2 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.signForm(f2);
		std::cout << f2 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.signForm(f2);
		std::cout << f2 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 7th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 2 Bureaucrats, make them sign 2 different forms\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("b2", 1);
		std::cout << b2 << std::endl;
		Form f1("f1", 1, 1);
		std::cout << f1 << std::endl;
		Form f2("f2", 1, 1);
		std::cout << f2 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.signForm(f2);
		std::cout << f2 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 8th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat, create a form with grade too high\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Form f1("f1", 151, 1);
		std::cout << f1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 9th Try ======\033[0m" << std::endl;
		std::cout << "\033[36mCreate 1 Bureaucrat, create a form with grade too low\033[0m" << std::endl;
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Form f1("f1", 0, 1);
		std::cout << f1 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}