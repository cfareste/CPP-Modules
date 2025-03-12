#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

void	Animal::makeSound()
{
	std::cout << "What sound does an animal do?" << std::endl;
}

Animal	&Animal::operator=(const Animal &animal)
{
	std::cout << "Animal copy assignment constructor called" << std::endl;
	if (this == &animal) return *this;

	this->type = animal.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
