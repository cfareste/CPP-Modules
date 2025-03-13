#pragma once

#include <string>

class WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wrong_animal);

		std::string	&getType();
		void	makeSound();

		WrongAnimal	&operator=(const WrongAnimal &wrong_animal);

		~WrongAnimal();
};
