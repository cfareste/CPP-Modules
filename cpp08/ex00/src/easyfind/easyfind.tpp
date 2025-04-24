#pragma once

#include "easyfind.hpp"
#include <exception>
#include <algorithm>
#include <iostream>
#include <sstream>

static std::string	getErrorMessage(int toFind)
{
	std::ostringstream	stream;

	stream << "Element '" << toFind << "' not found";
	return stream.str();
}

template<typename T>
void	easyfind(T &input, int toFind)
{
	typename T::iterator	element = std::find(input.begin(), input.end(), toFind);

	if (element == input.end())
		throw std::runtime_error(getErrorMessage(toFind));
	std::cout << "Element '" << toFind << "' found at index: " << std::distance(input.begin(), element) << std::endl;
}
