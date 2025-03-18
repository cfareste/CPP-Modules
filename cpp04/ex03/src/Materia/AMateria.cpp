#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &materia)
{
	*this = materia;
}

std::string const	&AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter &target)
{
	(void) target;
	std::cout << "Undefined materia behavior" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &materia)
{
	if (this == &materia) return *this;

	this->type = materia.type;
	return *this;
}

AMateria::~AMateria()
{
}
