#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie;

	zombie = newZombie("Tas Zombie");
	zombie->announce();
	randomChump("Pile Zombie");
	delete zombie;
	return (0);
}