#include "command.hpp"
#include <iostream>

std::string	read_command(void)
{
	std::string	input;

	std::cout << "Enter a command: ";
	std::cin >> input;
	return input;
}

void	execute_command(std::string &command)
{
	if (command == "ADD")
		std::cout << "Adding contact" << std::endl;
	else if (command == "SEARCH")
		std::cout << "Searching contact" << std::endl;
}
