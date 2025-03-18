#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		this->materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materia_source)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		this->materias[i] = nullptr;
	}
	*this = materia_source;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "Learning materia..." << std::endl;
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
	std::cout << "Creating materia..." << std::endl;
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		if (this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return nullptr;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &materia_source)
{
	std::cout << "MateriaSource copy assignment constructor called" << std::endl;
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
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < SOURCE_SIZE; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}
