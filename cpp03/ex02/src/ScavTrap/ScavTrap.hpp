#pragma once

#include "ClapTrap/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		ScavTrap();

	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &st);

		void	attack(const std::string &target);
		void	guardGate();

		ScavTrap	&operator=(const ScavTrap &st);

		~ScavTrap();
};

std::ostream	&operator<<(std::ostream &stream, ScavTrap &scav_trap);
