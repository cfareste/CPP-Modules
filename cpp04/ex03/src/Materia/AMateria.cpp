#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &materia)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = materia;
}

std::string const	&AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(/*ICharacter &target*/)
{
	std::cout << "Undefined materia behavior" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &materia)
{
	std::cout << "AMateria copy assignment constructor called" << std::endl;
	if (this == &materia) return *this;

	this->type = materia.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}
