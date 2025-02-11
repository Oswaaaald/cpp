#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat kaporal("kaporal", 1);
	Bureaucrat vicekaporal("vicekaporal", 10);
	Bureaucrat bureaucrat("bureaucrat", 40);
	Bureaucrat mercenary("mercenary", 135);
	Bureaucrat dumbguy("dumbguy", 150);

	AForm *treeForm = new ShrubberyCreationForm("siuuuu");
	AForm *treeForm2 = new ShrubberyCreationForm("siuuuu");
	AForm *robotForm = new RobotomyRequestForm("student");
	AForm *robotForm2 = new RobotomyRequestForm("student");
	AForm *pardonForm = new PresidentialPardonForm("prisoner");
	AForm *pardonForm2 = new PresidentialPardonForm("prisoner");

	std::cout << "Bureaucrat and Forms:" << std::endl;
	std::cout << kaporal << std::endl;
	std::cout << vicekaporal << std::endl;
	std::cout << mercenary << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << dumbguy << std::endl;
	std::cout << *treeForm << std::endl;
	std::cout << *treeForm2 << std::endl;
	std::cout << *robotForm << std::endl;
	std::cout << *robotForm2 << std::endl;
	std::cout << *pardonForm << std::endl;
	std::cout << *pardonForm2 << std::endl;

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 1st Try ======\033[0m" << std::endl;
		std::cout << "\033[36mBasic Shrubbery usage with 2 guys\033[0m" << std::endl;
		std::cout << *treeForm << std::endl;
		kaporal.signForm(*treeForm);
		std::cout << *treeForm << std::endl;
		mercenary.executeForm(*treeForm);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 2nd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mShrubbery try execute but not signed\033[0m" << std::endl;
		std::cout << *treeForm2 << std::endl;
		mercenary.executeForm(*treeForm2);
		std::cout << *treeForm2 << std::endl;
		kaporal.signForm(*treeForm2);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 3rd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mShrubbery try execute but no permissions\033[0m" << std::endl;
		std::cout << *treeForm2 << std::endl;
		kaporal.signForm(*treeForm2);
		std::cout << *treeForm2 << std::endl;
		dumbguy.executeForm(*treeForm2);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 1st Try ======\033[0m" << std::endl;
		std::cout << "\033[36mBasic Robotomy usage with 2 guys\033[0m" << std::endl;
		std::cout << *robotForm << std::endl;
		kaporal.signForm(*robotForm);
		std::cout << *robotForm << std::endl;
		bureaucrat.executeForm(*robotForm);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 2nd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mRobotomy try execute but not signed\033[0m" << std::endl;
		std::cout << *robotForm2 << std::endl;
		bureaucrat.executeForm(*robotForm2);
		std::cout << *robotForm2 << std::endl;
		kaporal.signForm(*robotForm2);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 3rd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mRobotomy try execute but no permissions\033[0m" << std::endl;
		std::cout << *treeForm2 << std::endl;
		kaporal.signForm(*treeForm2);
		std::cout << *treeForm2 << std::endl;
		mercenary.executeForm(*treeForm2);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 1st Try ======\033[0m" << std::endl;
		std::cout << "\033[36mBasic Robotomy usage with 2 guys\033[0m" << std::endl;
		std::cout << *pardonForm << std::endl;
		kaporal.signForm(*pardonForm);
		std::cout << *pardonForm << std::endl;
		mercenary.executeForm(*pardonForm);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 2nd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mRobotomy try execute but not signed\033[0m" << std::endl;
		std::cout << *pardonForm2 << std::endl;
		mercenary.executeForm(*pardonForm2);
		std::cout << *pardonForm2 << std::endl;
		kaporal.signForm(*pardonForm2);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 3rd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mRobotomy try execute but no permissions\033[0m" << std::endl;
		std::cout << *pardonForm2 << std::endl;
		kaporal.signForm(*pardonForm2);
		std::cout << *pardonForm2 << std::endl;
		dumbguy.executeForm(*pardonForm2);
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	delete treeForm;
	delete treeForm2;
	delete robotForm;
	delete robotForm2;
	delete pardonForm;
	delete pardonForm2;

	return 0;
}