#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &sc)
{
	(void) sc;
}

int	ScalarConverter::getNumOfOccurrences(std::string &str, char c)
{
	int	numOfOccurrences = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c)
			numOfOccurrences++;
	}
	return numOfOccurrences;
}

void ScalarConverter::handleUndefinedType(std::string &input)
{
	std::cout << "The input '" << input << "' has an undefined type."
		<< " Only char, int, float and double are supported" << std::endl;
}

bool	ScalarConverter::isWellFormatted(std::string &input)
{
	if (ScalarConverter::getNumOfOccurrences(input, '.') > 1) return false;
	if (ScalarConverter::getNumOfOccurrences(input, 'f') > 1) return false;
	if (!std::isdigit(input.at(0)) && input.at(0) != '+' && input.at(0) != '-') return false;

	int	inputLength = input.length();
	for (int i = 1; i < inputLength; i++)
	{
		char	currentChar = input.at(i);

		if (!std::isdigit(currentChar) && currentChar != '.')
		{
			if (currentChar == 'f' && i == inputLength - 1)
				continue ;
			return false;
		}
	}
	return true;
}

bool	ScalarConverter::isChar(std::string &input)
{
	if (input.length() == 1 && std::isprint(input.at(0)) && !std::isdigit(input.at(0)))
		return true;
	return false;
}

bool	ScalarConverter::isPseudoLiteral(std::string &input)
{
	if (input == "+inf" || input == "-inf" || input == "nan"
		|| input == "+inff" || input == "-inff" || input == "nanf")
		return true;
	return false;
}

t_InputTypes	ScalarConverter::getType(std::string &input)
{
	if (input.empty()) return UNDEFINED;

	if (ScalarConverter::isChar(input))
		return CHAR;
	if (ScalarConverter::isPseudoLiteral(input))
		return PSEUDO_LITERAL;
	if (!ScalarConverter::isWellFormatted(input))
		return UNDEFINED;
	if (input.find('f') != std::string::npos)
		return FLOAT;
	if (input.find('.') != std::string::npos)
		return DOUBLE;
	return INT;
}

void	ScalarConverter::convert(std::string input)
{
	t_InputTypes	inputType = ScalarConverter::getType(input);

	if (inputType == UNDEFINED) return ScalarConverter::handleUndefinedType(input);
	std::cout << "Input: " << input << " | Type: " << inputType << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &sc)
{
	(void) sc;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}
