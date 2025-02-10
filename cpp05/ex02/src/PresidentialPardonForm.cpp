#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "\033[33mPresidentialPardonForm default constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[33mPresidentialPardonForm constructor with assigned target called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "\033[33mPresidentialPardonForm copy constructor called\033[0m" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "\033[33mPresidentialPardonForm assignation operator called\033[0m" << std::endl;
	(void)copy;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
