#ifndef WRONTCAT_HPP
# define WRONTCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain* _brain;

	public:
		WrongCat();
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &copy);
		~WrongCat();

		void makeSound() const;
		Brain* getBrain() const;
};

#endif