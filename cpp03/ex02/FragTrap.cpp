#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "\033[33mFragTrap default constructor called\033[0m" << std::endl;
	this->_name = "FIZZ";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "\033[33mFragTrap constructor with assigned name called\033[0m" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "\033[33mFragTrap copy constructor called\033[0m" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[33mFragTrap destructor called\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		std::cout << "\033[33mFragTrap copy assignment operator returned\033[0m" << std::endl;
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "\033[97mFragTrap " << this->_name << " is asking for a high five\033[0m" << std::endl;
}