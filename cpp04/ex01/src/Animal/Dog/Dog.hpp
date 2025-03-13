#pragma once

#include "Animal/Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &dog);

		void	makeSound();

		Dog	&operator=(const Dog &dog);

		~Dog();
};
