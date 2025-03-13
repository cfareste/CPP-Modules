#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = animal;
}

std::string	&AAnimal::getType()
{
	return this->type;
}

void	AAnimal::makeSound()
{
	std::cout << "What sound does an animal do?" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &animal)
{
	std::cout << "AAnimal copy assignment constructor called" << std::endl;
	if (this == &animal) return *this;

	this->type = animal.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}
