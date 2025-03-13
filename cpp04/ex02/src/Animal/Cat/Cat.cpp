#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	this->brain->addIdea("Breathe");
	this->brain->addIdea("Mice");
	this->brain->addIdea("Feline parkour");
	this->brain->addIdea("Scratch inferior beings");
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

void	Cat::addThought(const std::string &thought)
{
	this->brain->addIdea(thought);
}

void	Cat::materializeThoughts()
{
	std::cout << "(((Inside this kitten's brain...))):" << std::endl;
	for (int i = 0; i < this->brain->getNumOfIdeas(); i++)
	{
		std::cout << "Idea " << i + 1 << ": " << this->brain->getIdea(i) << std::endl;
	}
	std::cout << "End of this brain!" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	std::cout << "Cat copy assignment constructor called" << std::endl;
	if (this == &cat) return *this;

	this->type = cat.type;
	*this->brain = *cat.brain;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}
