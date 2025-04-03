#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);
		virtual ~WrongAnimal();

		std::string getType() const;
		void makeSound() const;
		Brain* getBrain() const;
};

#endif