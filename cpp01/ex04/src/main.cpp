#include "Replacer/Replacer.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong usage: sedIsForLosers [filename] [occurrence] [replacement]" << std::endl;
		return EXIT_FAILURE;
	}
	if (argv[2][0] == '\0')
	{
		std::cout << "The occurrence string must be valid and non-zero" << std::endl;
		return EXIT_FAILURE;
	}

	int	status = Replacer::replace(argv[1], argv[2], argv[3]);
	return status;
}
