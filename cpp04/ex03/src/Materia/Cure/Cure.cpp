#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure &cure)
{
	*this = cure;
}

AMateria	*Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure	&Cure::operator=(const Cure &cure)
{
	if (this == &cure) return *this;

	this->type = cure.type;
	return *this;
}

Cure::~Cure()
{
}
