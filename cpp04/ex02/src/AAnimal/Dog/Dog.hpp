#pragma once

#include "AAnimal/AAnimal.hpp"
#include "Brain/Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(const Dog &dog);

		void	makeSound();
		void	addThought(const std::string &thought);
		void	materializeThoughts();

		Dog	&operator=(const Dog &dog);

		~Dog();
};
