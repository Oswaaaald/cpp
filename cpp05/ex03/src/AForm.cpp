#include "../includes/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "\033[33mForm default constructor called\033[0m" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "\033[33mForm constructor with assigned name called\033[0m" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "\033[33mForm copy constructor called\033[0m" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "\033[33mForm assignation operator called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->_signed = copy._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "\033[33mForm destructor called\033[0m" << std::endl;
}

const std::string &AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AForm::FormAlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "\033[31;3mform grade is too high.\033[0m";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "\033[31;3mform grade is too low.\033[0m";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "\033[31;3mform is already signed.\033[0m";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "\033[31;3mform is not signed.\033[0m";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	if (form.getSigned())
		out << "Form " << form.getName() << " is signed. Grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".";
	else
		out << "Form " << form.getName() << " is not signed. Grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".";
	return out;
}
