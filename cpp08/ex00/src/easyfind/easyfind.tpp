#pragma once

#include "easyfind.hpp"
#include <exception>
#include <algorithm>
#include <iostream>
#include <sstream>

template<typename T>
void	easyfind(T &input, int toFind)
{
	typename T::iterator	element = std::find(input.begin(), input.end(), toFind);

	if (element == input.end())
		throw std::runtime_error((std::ostringstream() << "Element '" << toFind << "' not found.").str());
	std::cout << "Element '" << toFind << "' found at index: " << std::distance(input.begin(), element) << std::endl;
}
