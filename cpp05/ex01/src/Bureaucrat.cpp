#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "\033[33mBureaucrat default constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	std::cout << "\033[33mBureaucrat constructor with assigned name called\033[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "\033[33mBureaucrat copy constructor called\033[0m" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "\033[33mBureaucrat assignation operator called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->_grade = copy._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[33mBureaucrat destructor called\033[0m" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[31;3mbureaucrate grade is too high\033[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[31;3mbureaucrate grade is too low\033[0m";
}

void Bureaucrat::signForm(Form &form) const
{
	try {
		form.beSigned(*this);
		std::cout << "\033[32m" << this->_name << " signed " << form.getName() << "\033[0m" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "\033[31;3m" << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		throw;
	}
}
