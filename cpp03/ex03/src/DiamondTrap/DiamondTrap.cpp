#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->setName(name + "_clap_name");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = dt;
}

const std::string	&DiamondTrap::getName() const
{
	return this->name;
}

const std::string &DiamondTrap::getClapTrapName() const
{
	return this->ClapTrap::getName();
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << ", a.k.a. " << this->getClapTrapName() << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &dt)
{
	std::cout << "DiamondTrap copy assignment constructor called" << std::endl;
	if (this == &dt) return *this;

	this->name = dt.name;
	this->setName(dt.getName());
	this->setHitPoints(dt.getHitPoints());
	this->setEnergyPoints(dt.getEnergyPoints());
	this->setAttackDamage(dt.getAttackDamage());
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const DiamondTrap &diamond_trap)
{
	stream << "DiamondTrap " << diamond_trap.getName()
		<< " (" << diamond_trap.getClapTrapName() << ") "
		<< " (HPs, EPs, AD): " << diamond_trap.getHitPoints() << ", " << diamond_trap.getEnergyPoints()
		<< ", " << diamond_trap.getAttackDamage();
	return stream;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
