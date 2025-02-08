#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "\033[33mDog default constructor called\033[0m" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const std::string &type) : Animal(type)
{
	std::cout << "\033[33mDog constructor with assigned name called\033[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "\033[33mDog copy constructor called\033[0m" << std::endl;
	this->type = copy.type;
}

Dog::~Dog()
{
	std::cout << "\033[33mDog destructor called\033[0m" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "\033[33mDog copy assignment operator called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->type = copy.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "WAF" << std::endl;
}
