#pragma once

#include "Weapon/Weapon.hpp"

class HumanA {
	private:
		std::string	name;
		Weapon		weapon;

	public:
		HumanA();
		HumanA(std::string &name, Weapon &weapon);

		void	attack();

		~HumanA();
};
