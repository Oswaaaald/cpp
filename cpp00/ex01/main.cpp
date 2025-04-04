#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	phoneBook.phoneBookInit();
	while (1)
	{
		std::string command;
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			return (-1);
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.displayAll();
		else if (command == "EXIT")
			break;
		else
		{
			std::cin.clear();
			std::cout << "Invalid command." << std::endl;
		}
	}
	return (0);
}