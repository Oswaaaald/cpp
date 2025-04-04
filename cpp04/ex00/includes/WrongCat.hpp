#ifndef WRONTCAT_HPP
# define WRONTCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &copy);
		~WrongCat();

		void makeSound() const;
};

#endif