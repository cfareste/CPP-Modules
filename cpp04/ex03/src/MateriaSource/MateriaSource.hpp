#pragma once

#define SOURCE_SIZE 4

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*materias[SOURCE_SIZE];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &materia_source);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

		MateriaSource	&operator=(const MateriaSource &materia_source);

		~MateriaSource();
};
