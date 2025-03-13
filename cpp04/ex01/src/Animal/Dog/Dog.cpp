#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	this->brain->addIdea("Breathe");
	this->brain->addIdea("Squishy toys");
	this->brain->addIdea("Go for a walk in the park");
	this->brain->addIdea("Treats");
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

void	Dog::materializeThoughts()
{
	std::cout << "(((Inside this puppy's brain...))):" << std::endl;
	for (int i = 0; i < this->brain->getNumOfIdeas(); i++)
	{
		std::cout << "Idea " << i + 1 << ": " << this->brain->getIdea(i) << std::endl;
	}
	std::cout << "End of this brain!" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Dog copy assignment constructor called" << std::endl;
	if (this == &dog) return *this;

	this->type = dog.type;
	delete this->brain;
	*this->brain = *dog.brain;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}
