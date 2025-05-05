#pragma once

#include <cstddef>

template <typename T>
class Array
{
private:
	T			*_elements;
	std::size_t	_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &array);

	std::size_t	size() const;

	Array	&operator=(const Array& array);
	T		&operator[](std::size_t index) const;

	~Array();
};

#include "Array.tpp"
