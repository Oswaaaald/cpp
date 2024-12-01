#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		nb_zombies = 5;

	horde = zombieHorde(nb_zombies, "Horde");
	for (int i = 0; i < nb_zombies; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}