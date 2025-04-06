#pragma once

#include <string>

typedef enum e_InputTypes
{
	UNDEFINED,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_LITERAL
}	t_InputTypes;

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &sc);

		static int			getNumOfOccurrences(std::string &str, char c);
		static void			handleUndefinedType(std::string &input);
		static bool			isWellFormatted(std::string &input);
		static bool			isChar(std::string &input);
		static bool			isPseudoLiteral(std::string &input);
		static t_InputTypes	getType(std::string &input);
		static bool			doesOverflow(std::string &input);
		static void			convertToChar(std::string &input, t_InputTypes &type);
		static void			convertToInt(std::string &input, t_InputTypes &type);
		static void			convertToFloat(std::string &input, t_InputTypes &type);
		static void			convertToDouble(std::string &input, t_InputTypes &type);

		ScalarConverter	&operator=(const ScalarConverter &sc);

		~ScalarConverter();

	public:
		static void	convert(std::string input);
};
