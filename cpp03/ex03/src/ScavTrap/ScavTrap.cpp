#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st.getName())
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = st;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is out of combat!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is too tired to combat" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->getName()
		<< " attacks " << target
		<< " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now in gate keeper mode" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &st)
{
	std::cout << "ScavTrap copy assignment constructor called" << std::endl;
	if (this == &st) return *this;

	this->setName(st.getName());
	this->setHitPoints(st.getHitPoints());
	this->setEnergyPoints(st.getEnergyPoints());
	this->setAttackDamage(st.getAttackDamage());
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, ScavTrap &scav_trap)
{
	stream << "ScavTrap " << scav_trap.getName() << " (HPs, EPs): "
		<< scav_trap.getHitPoints() << ", " << scav_trap.getEnergyPoints();
	return stream;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
