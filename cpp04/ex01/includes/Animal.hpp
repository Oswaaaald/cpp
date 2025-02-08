#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
		virtual Brain* getBrain() const;
};

#endif