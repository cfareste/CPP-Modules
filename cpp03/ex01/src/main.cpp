#include "ScavTrap/ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap	cake = ScavTrap("Cake");

	std::cout << cake << std::endl;

	cake.attack("Dummy");
	cake.takeDamage(2);
	cake.beRepaired(1);
	
	std::cout << cake << std::endl;

	cake.guardGate();
	return 0;
}
