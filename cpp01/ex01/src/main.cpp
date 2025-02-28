#include "Zombie/Zombie.hpp"
#include <iostream>

int	main()
{
	int	horde_size = 10;

	Zombie	*horde = zombieHorde(horde_size, "NPC zombie");

	for (int i = 0; i < horde_size; i++)
	{
		std::cout << i + 1 << ". ";
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
