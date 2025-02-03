#include "Contact/Contact.hpp"
#include "PhoneBook/PhoneBook.hpp"
#include <iostream>

static std::string	read_command(void)
{
	std::string	input;

	std::cout << "Enter a command: ";
	std::cin >> input;
	return input;
}

static void	execute_command(std::string &command)
{
	if (command == "ADD")
		std::cout << "Adding contact" << std::endl;
	else if (command == "SEARCH")
		std::cout << "Searching contact" << std::endl;
}

int	main(void)
{
	std::string	command = "";

	while (command != "EXIT")
	{
		command = read_command();
		execute_command(command);
	}
	return 0;
}
