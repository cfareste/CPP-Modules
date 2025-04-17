#include "Span.hpp"
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <iostream>

Span::Span() : _size(0), _occupied(0), _numbers(NULL)
{
}

Span::Span(unsigned int N) : _size(N), _occupied(0), _numbers(new int[N]())
{
}

Span::Span(const Span &other) : _numbers(NULL)
{
	*this = other;
}

void	Span::addNumber(const int num)
{
	if (this->_occupied >= this->_size)
		throw std::overflow_error("Span is full");

	this->_numbers[this->_occupied] = num;
	this->_occupied++;
}

int	Span::shortestSpan() const
{
	if (this->_occupied <= 1)
		throw std::logic_error("Insufficient numbers to calculate shortest span");

	int	shortestSpan = INT_MAX, current_diff = 0;
	std::sort(this->_numbers, this->_numbers + this->_occupied);
	for (unsigned int i = 0; i < this->_occupied - 1; i++)
	{
		current_diff = std::abs(this->_numbers[i + 1] - this->_numbers[i]);
		if (current_diff < shortestSpan)
			shortestSpan = current_diff;
	}
	return shortestSpan;
}

int	Span::longestSpan() const
{
	if (this->_occupied <= 1)
		throw std::logic_error("Insufficient numbers to calculate longest span");

	const int	*max = std::max_element(this->_numbers, this->_numbers + this->_occupied);
	const int	*min = std::min_element(this->_numbers, this->_numbers + this->_occupied);

	return std::abs(*max - *min);
}

void	Span::listNumbers() const
{
	for (unsigned int i = 0; i < this->_occupied; i++)
	{
		std::cout << this->_numbers[i] << " ";
	}
	std::cout << std::endl;
}

Span	&Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;

	this->_size = other._size;
	this->_occupied = other._occupied;
	delete[] this->_numbers;
	this->_numbers = new int[other._size]();
	for (unsigned int i = 0; i < other._occupied && i < other._size; i++)
	{
		this->_numbers[i] = other._numbers[i];
	}
	return *this;
}

Span::~Span()
{
	delete[] this->_numbers;
}
