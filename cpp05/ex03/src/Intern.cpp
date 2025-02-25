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
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;
	
	while (i < 3 && forms[i] != name)
		i++;

	switch (i)
	{
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			throw FormNotFoundException();
	}
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}
