#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::phoneBookInit()
{
	_nbContacts = -1;
	_next = 0;
}

void PhoneBook::addContact()
{
	if (_nbContacts < 7 || (_nbContacts == 7 && _next <= 8))
	{
		if (_next == 8)
			_next = 0;
		_contacts[_next].setContact();
		if (_nbContacts < 7)
			_nbContacts++;
		_next++;
	}
}

void PhoneBook::displayAll()
{
	if (_nbContacts == -1)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}
	std::cout << "|     index|First Name| Last Name| Nick Name|" << std::endl;
	std::cout << "|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|¯¯¯¯¯¯¯¯¯¯|" << std::endl;
	for (int i = 0; i <= _nbContacts; i++)
		_contacts[i].displayContact(i);
	std::cout << "Enter the id of the contact you want to display: ";
	std::string index;
	while (!std::getline(std::cin, index) || index.size() != 1 || !isdigit(index[0]) || index[0] - 48 > _nbContacts || index[0] - 48 < 0)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(-1);
		}
		else
		{
			std::cin.clear();
			std::cout << "Invalid input." << std::endl  << "Enter the id of the contact you want to display: ";
		}
	}
	_contacts[index[0] - 48].displayAllContact();
}