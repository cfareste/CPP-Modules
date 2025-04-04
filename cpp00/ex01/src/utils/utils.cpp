#include "utils.hpp"
#include <sstream>

bool is_num(std::string &str)
{
	size_t	i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;

	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

std::string	ltos(long num)
{
	std::stringstream	stream;

	stream << num;
	return stream.str();
}
