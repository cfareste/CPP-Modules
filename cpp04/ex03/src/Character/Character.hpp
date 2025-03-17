#pragma once

#define INVENTORY_SIZE 4

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string	name;
		AMateria	*inventory[INVENTORY_SIZE];

		Character();

	public:
		Character(const std::string &name);
		Character(const Character &character);

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		Character	&operator=(const Character &character);

		~Character();
};
