#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "\033[33mWrongAnimal default constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
	std::cout << "\033[33mWrongAnimal constructor with assigned name called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type)
{
	std::cout << "\033[33mWrongAnimal copy constructor called\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[33mWrongAnimal destructor called\033[0m" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "\033[33mWrongAnimal copy constructor called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->type = copy.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Not Animal sound" << std::endl;
}
