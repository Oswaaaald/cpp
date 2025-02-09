#include "../includes/Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "\033[33mForm default constructor called\033[0m" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "\033[33mForm constructor with assigned name called\033[0m" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "\033[33mForm copy constructor called\033[0m" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "\033[33mForm assignation operator called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->_signed = copy._signed;
	return *this;
}

Form::~Form()
{
	std::cout << "\033[33mForm destructor called\033[0m" << std::endl;
}

const std::string &Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw Form::FormAlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "\033[31;3mform grade is too high.\033[0m";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "\033[31;3mform grade is too low.\033[0m";
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return "\033[31;3mform is already signed.\033[0m";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	if (form.getSigned())
		out << "Form " << form.getName() << " is signed. Grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".";
	else
		out << "Form " << form.getName() << " is not signed. Grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".";
	return out;
}
