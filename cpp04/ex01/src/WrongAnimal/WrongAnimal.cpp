#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrong_animal;
}

std::string	&WrongAnimal::getType()
{
	return this->type;
}

void WrongAnimal::makeSound()
{
	std::cout << "What sound does a wrong animal do?" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wrong_animal)
{
	std::cout << "WrongAnimal copy assignment constructor called" << std::endl;
	if (this == &wrong_animal) return *this;

	this->type = wrong_animal.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
