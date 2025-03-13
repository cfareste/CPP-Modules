#pragma once

#include <string>

class AAnimal {
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal(const AAnimal &animal);

		std::string	&getType();
		virtual void	makeSound() = 0;

		AAnimal	&operator=(const AAnimal &animal);

		virtual ~AAnimal();
};
