#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	this->last_idea_index = 0;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

void	Brain::addIdea(const std::string &idea)
{
	if (this->last_idea_index < 0)
	{
		this->last_idea_index = 0;
	}
	if (this->last_idea_index >= MAX_IDEAS)
	{
		this->last_idea_index = MAX_IDEAS - 1;
	}

	this->ideas[this->last_idea_index] = idea;
	this->last_idea_index++;
}

std::string	Brain::getIdea(int index)
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cout << "This brain is melting! (idea index out of bounds)" << std::endl;
		return "";
	}
	return this->ideas[index];
}

int	Brain::getNumOfIdeas()
{
	return this->last_idea_index;
}

Brain	&Brain::operator=(const Brain &brain)
{
	std::cout << "Brain copy assignment constructor called" << std::endl;
	if (this == &brain) return *this;

	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
	this->last_idea_index = brain.last_idea_index;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
