#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "\033[33mCat default constructor called\033[0m" << std::endl;
	this->type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const std::string &type) : Animal(type)
{
	std::cout << "\033[33mCat constructor with assigned name called\033[0m" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "\033[33mCat copy constructor called\033[0m" << std::endl;
	this->type = copy.type;
	this->_brain = new Brain(*copy._brain);
}

Cat::~Cat()
{
	std::cout << "\033[33mCat destructor called\033[0m" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "\033[33mCat copy assignment operator called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	this->type = copy.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MIOW" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}
