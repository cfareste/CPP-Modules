#pragma once

#include "ClapTrap/ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
		FragTrap();

	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &st);

		void	highFivesGuys();

		FragTrap	&operator=(const FragTrap &st);

		~FragTrap();
};

std::ostream	&operator<<(std::ostream &stream, FragTrap &scav_trap);
