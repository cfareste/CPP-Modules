#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		this->materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materia_source)
{
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		this->materias[i] = nullptr;
	}
	*this = materia_source;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		if (this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return nullptr;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &materia_source)
{
	if (this == &materia_source) return *this;

	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		AMateria	*new_materia = nullptr;
		if (this->materias[i])
			delete this->materias[i];
		if (materia_source.materias[i])
			new_materia = this->materias[i]->clone();
		this->materias[i] = new_materia;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}
