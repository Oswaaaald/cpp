#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

int Contact::isPrintable(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isprint(str[i]))
			return (0);
	}
	return (1);
}

std::string Contact::checkInput(std::string message)
{
	std::string input;
	while (1)
	{
		std::cout << message;
		if (!std::getline(std::cin, input) || std::cin.eof() || std::cin.fail())
		{
			std::cout << std::endl;
			break;
		}
		if (isPrintable(input) && input.length() > 0)
			break;
		std::cin.clear();
		std::cout << "Invalid input." << std::endl;
	}
	return (input);
}

void Contact::setContact()
{
	_firstName = checkInput("Enter first name: ");
	_lastName = checkInput("Enter last name: ");
	_nickname = checkInput("Enter nickname: ");
	_phoneNumber = checkInput("Enter phone number: ");
	_darkestSecret = checkInput("Enter darkest secret: ");
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