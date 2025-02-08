#include "../includes/Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "\033[33mAnimal default constructor called\033[0m" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "\033[33mAnimal constructor with assigned name called\033[0m" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
	std::cout << "\033[33mAnimal copy constructor called\033[0m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[33mAnimal destructor called\033[0m" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "\033[33mAnimal copy assignment operator called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->type = copy.type;
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

Brain *Animal::getBrain() const
{
	return NULL;
}
