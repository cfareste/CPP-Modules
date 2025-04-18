#pragma once

#include "Span.hpp"
#include <iterator>
#include <stdexcept>

template<typename It>
void	Span::fill(It begin, It end)
{
	if (std::distance(begin, end) + this->_occupied > this->_size)
		throw std::overflow_error("Range doesn't fit in Span");

	for (; begin != end; ++begin)
		this->addNumber(*begin);
}
