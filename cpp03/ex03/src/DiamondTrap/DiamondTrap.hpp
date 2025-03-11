#pragma once

#include "ScavTrap/ScavTrap.hpp"
#include "FragTrap/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	name;

		DiamondTrap();

	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &dt);

		const std::string	&getName() const;
		const std::string	&getClapTrapName() const;

		void	whoAmI();

		DiamondTrap	&operator=(const DiamondTrap &dt);

		~DiamondTrap();
};

std::ostream	&operator<<(std::ostream &stream, const DiamondTrap &dt);
