#include "DiamondTrap/DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap	vortex = DiamondTrap("Vortex");

	std::cout << vortex << std::endl;

	vortex.attack("Nautilus");
	vortex.takeDamage(10);
	vortex.beRepaired(2);

	std::cout << vortex << std::endl;

	vortex.guardGate();
	vortex.highFivesGuys();
	vortex.whoAmI();

	return 0;
}
