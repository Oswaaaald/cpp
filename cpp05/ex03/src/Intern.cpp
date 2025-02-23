#include "../includes/Intern.hpp"

Intern::Intern()
{
	std::cout << "\033[33mIntern default constructor called\033[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "\033[33mIntern copy constructor called\033[0m" << std::endl;
	(void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "\033[33mIntern assignation operator called\033[0m" << std::endl;
	(void)copy;
	return *this;
}

Intern::~Intern()
{
	std::cout << "\033[33mIntern destructor called\033[0m" << std::endl;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	if (name == "ShrubberyCreationForm")
		return new ShrubberyCreationForm(target);
	else if (name == "RobotomyRequestForm")
		return new RobotomyRequestForm(target);
	else if (name == "PresidentialPardonForm")
		return new PresidentialPardonForm(target);
	else
		throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}
