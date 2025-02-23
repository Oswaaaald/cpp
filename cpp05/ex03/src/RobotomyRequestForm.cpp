#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "\033[33mRobotomyRequestForm default constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[33mRobotomyRequestForm constructor with assigned target called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "\033[33mRobotomyRequestForm copy constructor called\033[0m" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "\033[33mRobotomyRequestForm assignation operator called\033[0m" << std::endl;
	(void)copy;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::cout << "Drilling noise" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization of " << this->_target << " has failed." << std::endl;
}
	