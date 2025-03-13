#include "AAnimal/AAnimal.hpp"
#include "AAnimal/Dog/Dog.hpp"
#include "AAnimal/Cat/Cat.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongAnimal/WrongCat/WrongCat.hpp"
#include <iostream>

int	main(void)
{
	AAnimal	*pets[] = {
		new Dog(),
		new Cat(),
		new Cat(),
		new Dog(),
		new Cat(),
		new Dog()
	};

	for (int i = 0; i < 6; i++)
	{
		std::cout << "Hey! I am a " << pets[i]->getType() << ", and I usually say ";
		pets[i]->makeSound();
	}
	for (int i = 0; i < 6; i++)
	{
		delete pets[i];
	}

	std::cout << std::endl;

	Dog	*laika = new Dog();
	Dog	*neil = new Dog();

	laika->materializeThoughts();
	neil->materializeThoughts();

	neil->addThought("Lick my human's face");
	neil->addThought("Concern about my human leaving the house");
	neil->addThought("Massive obliteration to every piece of furniture of my human's house");

	laika->materializeThoughts();
	neil->materializeThoughts();

	*laika = *neil;

	laika->materializeThoughts();
	neil->materializeThoughts();

	delete laika;
	delete neil;

	std::cout << std::endl;

	Cat	*garfield = new Cat();

	garfield->addThought("Play with a wool skein");
	garfield->addThought("Hunt some innocent cockroach");
	garfield->addThought("Scratch the hell out of my servant's (human) forearm");

	garfield->materializeThoughts();

	Cat	*paws = new Cat(*garfield);

	paws->materializeThoughts();

	delete garfield;
	delete paws;

	return 0;
}
