#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("golf club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("baseball bat");
		bob.attack();
	}
	{
		Weapon club = Weapon("blue table");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("red table");
		jim.attack();

		HumanB max("Max");
		max.attack();
	}
	return 0;
}
