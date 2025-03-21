#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &st) : ClapTrap(st.getName())
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = st;
}

void	FragTrap::highFivesGuys()
{
	std::string	high_five;

	std::cout << "FragTrap " << this->getName() << ": give me a high five!: ";
	std::getline(std::cin, high_five);
}

FragTrap	&FragTrap::operator=(const FragTrap &ft)
{
	std::cout << "FragTrap copy assignment constructor called" << std::endl;
	if (this == &ft) return *this;

	this->setName(ft.getName());
	this->setHitPoints(ft.getHitPoints());
	this->setEnergyPoints(ft.getEnergyPoints());
	this->setAttackDamage(ft.getAttackDamage());
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, FragTrap &frag_trap)
{
	stream << "FragTrap " << frag_trap.getName() << " (HPs, EPs): "
		<< frag_trap.getHitPoints() << ", " << frag_trap.getEnergyPoints();
	return stream;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
