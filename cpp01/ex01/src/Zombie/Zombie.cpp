#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie()
{
	this->name = "";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::set_name(std::string &name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "The zombie '" << this->name << "' is now an un-undead" << std::endl;
}
