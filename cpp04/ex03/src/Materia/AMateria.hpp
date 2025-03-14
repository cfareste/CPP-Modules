#pragma once

#include "Character/ICharacter.hpp"
#include <string>

class AMateria {
	protected:
		std::string	type;

		AMateria();

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &materia);

		std::string const	&getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);

		AMateria	&operator=(const AMateria &materia);

		virtual ~AMateria();
};
