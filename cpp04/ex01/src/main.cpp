#include "Animal/Animal.hpp"
#include "Animal/Dog/Dog.hpp"
#include "Animal/Cat/Cat.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongAnimal/WrongCat/WrongCat.hpp"
#include <iostream>

int	main(void)
{
	Animal	*animal = new Animal();
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	WrongAnimal	*wrong_animal = new WrongAnimal();
	WrongAnimal	*wrong_cat = new WrongCat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << wrong_cat->getType() << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrong_animal->makeSound();
	wrong_cat->makeSound();

	delete animal;
	delete dog;
	delete cat;
	delete wrong_animal;
	delete wrong_cat;

	return 0;
}
