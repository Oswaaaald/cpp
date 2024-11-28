#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string _darkestSecret;
public:
	Contact();
	~Contact();

	void setContact();
	void displayContact(int index);
	void displayAllContact();
	int isPrintable(std::string str);
	std::string checkInput(std::string message);
};

#endif