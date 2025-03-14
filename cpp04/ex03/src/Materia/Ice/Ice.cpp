#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &ice)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = ice;
}

AMateria	*Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(/*ICharacter &target*/)
{
	std::cout << "* shoots an ice bolt at " /*<< target.getName()*/ << " *" << std::endl;
}

Ice	&Ice::operator=(const Ice &ice)
{
	std::cout << "Ice copy assignment constructor called" << std::endl;
	if (this == &ice) return *this;

	this->type = ice.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}
