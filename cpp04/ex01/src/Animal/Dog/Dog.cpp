#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

void	Dog::makeSound()
{
	std::cout << "BARK BARK!" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Dog copy assignment constructor called" << std::endl;
	if (this == &dog) return *this;

	this->type = dog.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
