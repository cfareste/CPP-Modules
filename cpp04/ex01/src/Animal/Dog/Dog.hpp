#pragma once

#include "Animal/Animal.hpp"
#include "Brain/Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*brain;

	public:
		Dog();
		Dog(const Dog &dog);

		void	makeSound();
		void	materializeThoughts();

		Dog	&operator=(const Dog &dog);

		~Dog();
};
