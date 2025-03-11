#pragma once

#include "ClapTrap/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		FragTrap();

	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &st);

		void	highFivesGuys();

		FragTrap	&operator=(const FragTrap &st);

		~FragTrap();
};

std::ostream	&operator<<(std::ostream &stream, FragTrap &scav_trap);
