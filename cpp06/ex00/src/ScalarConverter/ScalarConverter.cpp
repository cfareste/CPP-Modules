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

bool	ScalarConverter::doesOverflow(std::string &input)
{
	if (input.length() > 11) return true;

	long long	num = std::atoll(input.c_str());
	if (num < std::numeric_limits<int>::min()
		|| num > std::numeric_limits<int>::max())
		return true;
	return false;
}

void	ScalarConverter::convertToChar(std::string &input, t_InputTypes &type)
{
	int	realValue = std::atoi(input.c_str());

	std::cout << "char: ";
	if (type == CHAR)
		std::cout << "'" << input << "'";
	else if (type == PSEUDO_LITERAL)
		std::cout << "impossible";
	else if (std::isprint(realValue))
		std::cout << "'" << static_cast<unsigned char>(realValue) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	ScalarConverter::convertToInt(std::string &input, t_InputTypes &type)
{
	std::cout << "int: ";
	if (ScalarConverter::doesOverflow(input) || type == PSEUDO_LITERAL)
		std::cout << "impossible";
	else if (type == CHAR)
		std::cout << static_cast<int>(input.at(0));
	else
		std::cout << std::atoi(input.c_str());
	std::cout << std::endl;
}

void	ScalarConverter::convertToFloat(std::string &input, t_InputTypes &type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	std::cout << "float: ";
	if (type == CHAR)
		std::cout << static_cast<float>(input.at(0));
	else
		std::cout << static_cast<float>(std::atof(input.c_str()));
	std::cout << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	ScalarConverter::convertToDouble(std::string &input, t_InputTypes &type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	std::cout << "double: ";
	if (type == CHAR)
		std::cout << static_cast<double>(input.at(0));
	else
		std::cout << static_cast<double>(std::atof(input.c_str()));
	std::cout << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	ScalarConverter::convert(std::string input)
{
	t_InputTypes	inputType = ScalarConverter::getType(input);

	if (inputType == UNDEFINED) return ScalarConverter::handleUndefinedType(input);

	ScalarConverter::convertToChar(input, inputType);
	ScalarConverter::convertToInt(input, inputType);
	ScalarConverter::convertToFloat(input, inputType);
	ScalarConverter::convertToDouble(input, inputType);
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &sc)
{
	(void) sc;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}
