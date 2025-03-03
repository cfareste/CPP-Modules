#include "Replacer/Replacer.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong usage: sedIsForLosers [filename] [occurrence] [replacement]" << std::endl;
		return EXIT_FAILURE;
	}
	Replacer::replace(argv[1], argv[2], argv[3]);
	return EXIT_SUCCESS;
}
