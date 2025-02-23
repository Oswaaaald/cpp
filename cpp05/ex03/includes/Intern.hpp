#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif