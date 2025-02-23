#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "\033[33mShrubberyCreationForm default constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[33mShrubberyCreationForm constructor with assigned target called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "\033[33mShrubberyCreationForm copy constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "\033[33mShrubberyCreationForm assignation operator called\033[0m" << std::endl;
	(void)copy;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		std::cout << "Error: could not open file" << std::endl;
	else
	{
		file << "              v .   ._, |_  .," << _target << std::endl;
		file << "       \'-._\\/  .  \\ /    |/_" << std::endl;
		file << "           \\\\  _\\, y | \\//" << std::endl;
		file << "     _\\_.___\\\\, \\\\/ -.\\||" << std::endl;
		file << "       \'7-,--.\'._||  / / ," << std::endl;
		file << "       /\'     \'-.\'./ / |/_.\'" << std::endl;
		file << "                 |    |//" << std::endl;
		file << "                 |_    /   " << std::endl;
		file << "                 |-   |" << std::endl;
		file << "                 |   =|" << std::endl;
		file << "                 |    |" << std::endl;
		file << "----------------/ ,  . \\--------._" << std::endl;
        file.close();
	}
}