#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
	Intern	aLambdaGuy;

	AForm	*treeForm = NULL;
	AForm	*treeForm2 = NULL;
	AForm	*treeForm3 = NULL;
	AForm	*robotForm = NULL;
	AForm	*robotForm2 = NULL;
	AForm	*robotForm3 = NULL;
	AForm	*pardonForm = NULL;
	AForm	*pardonForm2 = NULL;
	AForm	*pardonForm3 = NULL;

	try {
		std::cout << "\033[35m======= 1st Try ======\033[0m" << std::endl;
		std::cout << "\033[36mFull success\033[0m" << std::endl;
		treeForm = aLambdaGuy.makeForm("ShrubberyCreationForm", "siuuuu");
		std::cout << *treeForm << std::endl;
		robotForm = aLambdaGuy.makeForm("RobotomyRequestForm", "student");
		std::cout << *robotForm << std::endl;
		pardonForm = aLambdaGuy.makeForm("PresidentialPardonForm", "prisoner");
		std::cout << *pardonForm << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 2nd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mFull fail\033[0m" << std::endl;
		treeForm2 = aLambdaGuy.makeForm("shrubbery", "siuuuu");
		std::cout << *treeForm2 << std::endl;
		robotForm2 = aLambdaGuy.makeForm("robotomy", "student");
		std::cout << *robotForm2 << std::endl;
		pardonForm2 = aLambdaGuy.makeForm("presidential", "prisoner");
		std::cout << *pardonForm2 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl;
		std::cout << "\033[35m======= 3rd Try ======\033[0m" << std::endl;
		std::cout << "\033[36mSecond one fails\033[0m" << std::endl;
		treeForm3 = aLambdaGuy.makeForm("ShrubberyCreationForm", "siuuuu");
		std::cout << *treeForm3 << std::endl;
		robotForm3 = aLambdaGuy.makeForm("I WANNAAA ROBOTOMY", "student");
		std::cout << *robotForm3 << std::endl;
		pardonForm3 = aLambdaGuy.makeForm("PresidentialPardonForm", "prisoner");
		std::cout << *pardonForm3 << std::endl;
		std::cout << "\033[32m======= SUCCESS ======\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "====== CATCH ======-" << std::endl;
		std::cout << e.what() << std::endl;
	}

	// Check copy constructor and assignation operator are working
	Intern	anotherLambdaGuy(aLambdaGuy);
	Intern	againAnotherLambdaGuy;
	againAnotherLambdaGuy = aLambdaGuy;

	delete treeForm;
	delete treeForm2;
	delete treeForm3;
	delete robotForm;
	delete robotForm2;
	delete robotForm3;
	delete pardonForm;
	delete pardonForm2;
	delete pardonForm3;
}