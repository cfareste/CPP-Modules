#pragma once

#include <string>

class Animal {
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &animal);

		void	makeSound();

		Animal	&operator=(const Animal &animal);

		~Animal();
};
