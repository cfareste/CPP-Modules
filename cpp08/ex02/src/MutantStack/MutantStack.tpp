#pragma once

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->begin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->end();
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return this->begin();
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return this->end();
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &other)
{
	if (this == &other)
		return *this;

	std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}
