#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their ";
	if (this->weapon)
	{
		std::cout << this->weapon->getType() << std::endl;
	}
	else
	{
		std::cout << "non-existant weapon" << std::endl;
	}
}

HumanB::~HumanB()
{
}
