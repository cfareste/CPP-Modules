#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
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

std::string	&ClapTrap::getName()
{
	return this->name;
}

int	ClapTrap::getHitPoints()
{
	return this->hit_points;
}

int	ClapTrap::getEnergyPoints()
{
	return this->energy_points;
}

void	ClapTrap::setName(const std::string &name)
{
	this->name = name;
}

void	ClapTrap::setHitPoints(unsigned int hit_points)
{
	this->hit_points = hit_points;
}

void	ClapTrap::setEnergyPoints(unsigned int energy_points)
{
	this->energy_points = energy_points;
}

void	ClapTrap::setAttackDamage(unsigned int attack_damage)
{
	this->attack_damage = attack_damage;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of combat!" << std::endl;
		return ;
	}
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is too tired to combat" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name
		<< " attacks " << target
		<< " causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name
		<< " took " << amount << " points of damage" << std::endl;
	this->hit_points -= amount;
	if (this->hit_points < 0)
		this->hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of combat!" << std::endl;
		return ;
	}
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is too tired to be repaired" << std::endl;
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

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clap_trap)
{
	stream << "ClapTrap " << clap_trap.getName() << " (HPs, EPs): "
		<< clap_trap.getHitPoints() << ", " << clap_trap.getEnergyPoints();
	return stream;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
