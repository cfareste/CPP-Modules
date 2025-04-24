#include "RPN/RPN.hpp"
#include <cstdlib>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		RPN	rpn = RPN();

		rpn.calculateRPN(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
