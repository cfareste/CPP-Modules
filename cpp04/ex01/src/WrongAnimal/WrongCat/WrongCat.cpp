#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrong_cat) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrong_cat;
}

void	WrongCat::makeSound()
{
	std::cout << "!WWOOOEEEEM" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &wrong_cat)
{
	std::cout << "WrongCat copy assignment constructor called" << std::endl;
	if (this == &wrong_cat) return *this;

	this->type = wrong_cat.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
