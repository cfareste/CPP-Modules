#pragma once

#include "WrongAnimal/WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &wrong_cat);

		void	makeSound();

		WrongCat	&operator=(const WrongCat &wrong_cat);

		~WrongCat();
};
