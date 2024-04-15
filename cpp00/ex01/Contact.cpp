#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setContact()
{
	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, _firstName))
		exit (-1);
	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, _lastName))
		exit (-1);
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, _nickname))
		exit (-1);
	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, _phoneNumber))
		exit (-1);
	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, _darkestSecret))
		exit (-1);
}

void Contact::displayContact(int index)
{
	std::cout << std::setw(1) << "|";
	std::cout << std::setw(10) << index << "|";
	if (_firstName.length() > 10)
		std::cout << _firstName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << _firstName << "|";
	if (_lastName.length() > 10)
		std::cout << _lastName.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << _lastName << "|";
	if (_nickname.length() > 10)
		std::cout << _nickname.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << _nickname << "|";
	std::cout << std::endl;
}

void Contact::displayAllContact()
{
	std::cout << "First Name : " << _firstName << std::endl;
	std::cout << "Last Name : " << _lastName << std::endl;
	std::cout << "Nick Name : " << _nickname << std::endl;
	std::cout << "Phone Number : " << _phoneNumber << std::endl;
	std::cout << "Dark Secret : " << _darkestSecret << std::endl;
}