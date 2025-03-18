#include "Character.hpp"
#include <iostream>

Character::Character()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		this->inventory[i] = nullptr;
	}
}

Character::Character(const std::string &name)
{
	this->name = name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		this->inventory[i] = nullptr;
	}
}

Character::Character(const Character &character)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		this->inventory[i] = nullptr;
	}
	*this = character;
}

std::string const	&Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria *m)
{
	if (!m) return ;

	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !this->inventory[idx]) return ;

	this->inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !this->inventory[idx]) return ;

	this->inventory[idx]->use(target);
}

Character	&Character::operator=(const Character &character)
{
	if (this == &character) return *this;

	this->name = character.name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		AMateria	*new_materia = nullptr;
		if (this->inventory[i])
			delete this->inventory[i];
		if (character.inventory[i])
			new_materia = this->inventory[i]->clone();
		this->inventory[i] = new_materia;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}
