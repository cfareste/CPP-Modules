#include "Character/Character.hpp"
#include "Materia/Cure/Cure.hpp"
#include "Materia/Ice/Ice.hpp"
#include "MateriaSource/MateriaSource.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);

	delete tmp;
	delete bob;
	delete me;
	delete src;
	return 0;
}
