#pragma once

#include "Array.hpp"
#include <exception>
#include <stdexcept>

template<typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n)
{
}

template<typename T>
Array<T>::Array(const Array &array) : _elements(new T[array._size]()), _size(array._size)
{
	for	(size_t i = 0; i < array._size; i++)
	{
		this->_elements[i] = array._elements[i];
	}
}

template<typename T>
std::size_t	Array<T>::size() const
{
	return this->_size;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &array)
{
	if (this == &array)
		return *this;

	delete[] this->_elements;
	this->_elements = NULL;
	if (array._size == 0)
		return *this;
	this->_elements = new T[array._size];
	for (size_t i = 0; i < array._size; i++)
		this->_elements[i] = array._elements[i];
	this->_size = array._size;
	return *this;
}

template<typename T>
T	&Array<T>::operator[](std::size_t index) const
{
	if (index >= this->_size)
		throw std::out_of_range("Array index is out of bounds");

	return this->_elements[index];
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_elements;
}
