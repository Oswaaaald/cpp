#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "\033[33mWrongCat default constructor called\033[0m" << std::endl;
	this->type = "NotCat";
	_brain = new Brain();
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout << "\033[33mWrongCat constructor with assigned name called\033[0m" << std::endl;
	_brain = new Brain();
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "\033[33mWrongCat copy constructor called\033[0m" << std::endl;
	this->type = copy.type;
	this->_brain = new Brain(*copy._brain);
}

WrongCat::~WrongCat()
{
	std::cout << "\033[33mWrongCat destructor called\033[0m" << std::endl;
	delete this->_brain;
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

Brain* WrongCat::getBrain() const
{
	return this->_brain;
}