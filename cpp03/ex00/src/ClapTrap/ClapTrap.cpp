#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = ct;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap is out of combat!" << std::endl;
		return ;
	}
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap is too tired to combat" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name
		<< " attacks " << target
		<< " causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name
		<< " took " << amount << " points of damage" << std::endl;
	this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap is out of combat!" << std::endl;
		return ;
	}
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap is too tired to combat" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name
		<< " repaired " << amount << " hit points " << std::endl;
	this->hit_points += amount;
	this->energy_points--;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ct)
{
	std::cout << "ClapTrap copy assignment constructor called" << std::endl;
	if (this == &ct) return *this;

	this->name = ct.name;
	this->hit_points = ct.hit_points;
	this->energy_points = ct.energy_points;
	this->attack_damage = ct.attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
