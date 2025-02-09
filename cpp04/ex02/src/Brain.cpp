#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[33mBrain default constructor called\033[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "\033[33mBrain copy constructor called\033[0m" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "\033[33mBrain copy constructor called\033[0m" << std::endl;
	if (this == &copy)
		return *this;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "\033[33mBrain destructor called\033[0m" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return "Invalid index";
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
	else
		std::cout << "Too much ideas" << std::endl;
}
