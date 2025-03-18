#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &ice)
{
	*this = ice;
}

AMateria	*Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice	&Ice::operator=(const Ice &ice)
{
	if (this == &ice) return *this;

	this->type = ice.type;
	return *this;
}

Ice::~Ice()
{
}
