#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "\033[33mWrongCat default constructor called\033[0m" << std::endl;
	this->type = "NotCat";
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout << "\033[33mWrongCat constructor with assigned name called\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "\033[33mWrongCat copy constructor called\033[0m" << std::endl;
	this->type = copy.type;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[33mWrongCat destructor called\033[0m" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "\033[33mWrongCat copy assignment operator called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->type = copy.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Not MIOW" << std::endl;
}
