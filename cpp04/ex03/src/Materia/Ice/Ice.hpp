#pragma once

#include "Materia/AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &ice);

		AMateria	*clone() const;
		void		use(ICharacter &target);

		Ice	&operator=(const Ice &ice);

		~Ice();
};
