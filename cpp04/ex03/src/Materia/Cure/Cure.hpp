#pragma once

#include "Materia/AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &cure);

		AMateria	*clone() const;
		void		use(/*ICharacter &target*/);

		Cure	&operator=(const Cure &cure);

		~Cure();
};
