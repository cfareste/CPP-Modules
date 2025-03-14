#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &cure)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = cure;
}

AMateria	*Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(/*ICharacter &target*/)
{
	std::cout << "* heals " /*<< target.getName()*/ << "'s wounds *" << std::endl;
}

Cure	&Cure::operator=(const Cure &cure)
{
	std::cout << "Cure copy assignment constructor called" << std::endl;
	if (this == &cure) return *this;

	this->type = cure.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}
