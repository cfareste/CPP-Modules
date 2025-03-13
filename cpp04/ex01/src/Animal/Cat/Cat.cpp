#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

void	Cat::makeSound()
{
	std::cout << "MEEEEOOOWW!" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	std::cout << "Cat copy assignment constructor called" << std::endl;
	if (this == &cat) return *this;

	this->type = cat.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
