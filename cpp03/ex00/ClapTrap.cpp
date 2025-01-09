#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("BUZZ"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[33mClapTrap default constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[33mClapTrap constructor with assigned name called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "\033[33mClapTrap copy constructor called\033[0m" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[33mClapTrap destructor called\033[0m" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		std::cout << "\033[33mClapTrap copy assignment operator returned\033[0m" << std::endl;
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_hitPoints <= 0 && this->_energyPoints <= 0)
		{
			std::cout << "\033[32;3mClapTrap " << this->_name << " is dead and out of energy and cannot attack\033[0m" << std::endl;
			return ;
		}
		if (this->_hitPoints <= 0)
			std::cout << "\033[32;3mClapTrap " << this->_name << " is dead and cannot attack\033[0m" << std::endl;
		if (this->_energyPoints <= 0)
			std::cout << "\033[32;3mClapTrap " << this->_name << " is out of energy and cannot attack\033[0m" << std::endl;
		return ;
	}
	else
	{
		std::cout << "\033[32mClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
		this->_energyPoints -= 1;
	}

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "\033[31;3mClapTrap " << this->_name << " is already dead\033[0m" << std::endl;
	else if (amount >= this->_hitPoints)
	{
		std::cout << "\033[31mClapTrap " << this->_name << " takes " << amount << " points of damage and dies\033[0m" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout << "\033[31mClapTrap " << this->_name << " takes " << amount << " points of damage\033[0m" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		if (this->_energyPoints <= 0 && this->_hitPoints <= 0)
		{
			std::cout << "\033[35;3mClapTrap " << this->_name << " is dead and out of energy and cannot be repaired\033[0m" << std::endl;
			return ;
		}
		if (this->_energyPoints <= 0)
			std::cout << "\033[35;3mClapTrap " << this->_name << " is out of energy and cannot be repaired\033[0m" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << "\033[35;3mClapTrap " << this->_name << " is dead and cannot be repaired\033[0m" << std::endl;
		return ;
	}
	else if (this->_hitPoints + amount >= 10)
	{
		std::cout << "\033[35mClapTrap " << this->_name << " is fully repaired\033[0m" << std::endl;
		this->_hitPoints = 10;
		this->_energyPoints -= 1;
	}
	else
	{
		std::cout << "\033[35mClapTrap " << this->_name << " is repaired by " << amount << " hitpoints\033[0m" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
	}
}

const std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getLife(void) const
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergy(void) const
{
	return (this->_energyPoints);
}
