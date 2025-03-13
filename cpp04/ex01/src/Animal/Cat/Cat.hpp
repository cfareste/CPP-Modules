#pragma once

#include "Animal/Animal.hpp"
#include "Brain/Brain.hpp"

class Cat : public Animal {
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat &cat);

		void	makeSound();
		void	addThought(const std::string &thought);
		void	materializeThoughts();

		Cat	&operator=(const Cat &cat);

		~Cat();
};
