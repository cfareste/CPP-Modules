#include "Harl/Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Wrong usage: harlFilter [complain]" << std::endl;
		return 1;
	}

	harl.complain(argv[1]);
	return 0;
}
