#include "FragTrap/FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap	nautilus = FragTrap("Nautilus");

	std::cout << nautilus << std::endl;

	nautilus.attack("Dummy");
	nautilus.takeDamage(10);
	nautilus.beRepaired(3);

	std::cout << nautilus << std::endl;

	nautilus.highFivesGuys();

	return 0;
}
