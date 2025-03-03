#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong usage: sedIsForLosers [filename] [occurrence] [replacement]" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
