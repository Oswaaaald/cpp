#ifndef PHOENBOOK_HPP
# define PHOENBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_nbContacts;
	int		_next;
public:
	PhoneBook();
	~PhoneBook();

	void	phoneBookInit();
	void	addContact();
	void	displayAll();
};

#endif