#include "ScalarConverter/ScalarConverter.hpp"
#include <iostream>

int	main(void)
{
	ScalarConverter::convert("a");
	ScalarConverter::convert("aa");
	ScalarConverter::convert("ç");
	ScalarConverter::convert("0");
	ScalarConverter::convert("6");
	ScalarConverter::convert("123");
	ScalarConverter::convert("+123");
	ScalarConverter::convert("-123");
	ScalarConverter::convert(".");
	ScalarConverter::convert("f");
	ScalarConverter::convert(".f");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("0.f");
	ScalarConverter::convert("0f");
	ScalarConverter::convert("+3123.0f");
	ScalarConverter::convert("-3123.0f");
	ScalarConverter::convert("032.0");
	ScalarConverter::convert("-32.0");
	ScalarConverter::convert("+32.0");
	ScalarConverter::convert("f132.0");
	ScalarConverter::convert("132f0.");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	return 0;
}
