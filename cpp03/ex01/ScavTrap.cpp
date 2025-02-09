#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "\033[33mScavTrap default constructor called\033[0m" << std::endl;
	this->_name = "FIZZ";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "\033[33mScavTrap constructor with assigned name called\033[0m" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "\033[33mScavTrap copy constructor called\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[33mScavTrap destructor called\033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		std::cout << "\033[33mScavTrap copy assignment operator returned\033[0m" << std::endl;
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "\033[97mScavTrap " << this->_name << " has entered in Gate keeper mode\033[0m" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "\033[31mScavTrap " << this->_name << " is dead and can't attack\033[0m" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "\033[31mScavTrap " << this->_name << " has no energy left to attack\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[32mScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
	this->_energyPoints -= 1;
}