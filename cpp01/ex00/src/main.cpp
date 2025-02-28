#include "Zombie/Zombie.hpp"

int	main()
{
	Zombie	*heap_zombie = newZombie("Heaped zombie");

	randomChump("Stacked zombie");
	heap_zombie->announce();
	randomChump("Stacked zombie 2");
	delete heap_zombie;
	return 0;
}
