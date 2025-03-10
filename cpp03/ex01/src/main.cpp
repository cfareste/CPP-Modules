#include "ClapTrap/ClapTrap.hpp"
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

	return 0;
}
