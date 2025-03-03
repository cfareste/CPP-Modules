#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}

Weapon &Weapon::operator=(const Weapon &weapon)
{
	if (this == &weapon)
		return *this;
	this->type = weapon.type;
	return *this;
}

Weapon::~Weapon()
{
}
