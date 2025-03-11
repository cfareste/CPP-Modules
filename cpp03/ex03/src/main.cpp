#include "ClapTrap/ClapTrap.hpp"
#include "ScavTrap/ScavTrap.hpp"
#include "FragTrap/FragTrap.hpp"
#include "DiamondTrap/DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	trinity = ClapTrap("Trinity");
	ClapTrap	xanax = ClapTrap("Xanax");
	ClapTrap	antares = ClapTrap("Antares");

	std::cout << trinity << std::endl;
	std::cout << xanax << std::endl;
	std::cout << antares << std::endl;

	trinity.attack("Xanax");
	xanax.attack("Antares");
	xanax.takeDamage(4);
	antares.takeDamage(12);

	std::cout << trinity << std::endl;
	std::cout << xanax << std::endl;
	std::cout << antares << std::endl;

	xanax.beRepaired(3);
	antares.beRepaired(4);
	antares.attack("Trinity");

	std::cout << trinity << std::endl;
	std::cout << xanax << std::endl;
	std::cout << antares << std::endl;

	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);
	xanax.beRepaired(1);

	std::cout << trinity << std::endl;
	std::cout << xanax << std::endl;
	std::cout << antares << std::endl;

	ScavTrap	cake = ScavTrap("Cake");

	std::cout << cake << std::endl;

	cake.attack("xanax");
	cake.guardGate();

	FragTrap	nautilus = FragTrap("Nautilus");

	std::cout << nautilus << std::endl;

	nautilus.highFivesGuys();

	DiamondTrap	vortex = DiamondTrap("Vortex");

	std::cout << vortex << std::endl;
	vortex.attack("Nautilus");
	vortex.whoAmI();

	return 0;
}
