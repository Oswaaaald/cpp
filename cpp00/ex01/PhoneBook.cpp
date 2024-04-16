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
	else
		std::cout << "Error" << std::endl;
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
	if (!std::getline(std::cin, index))
		exit (-1);
	if (index.size() != 1 || !isdigit(index[0]))
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	int ind = (int) index[0] - 48;
	if (ind >= 0 && ind <= _nbContacts)
		_contacts[ind].displayAllContact();
	else
		std::cout << "Error" << std::endl;
}