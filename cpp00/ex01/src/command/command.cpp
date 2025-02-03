#include "command.hpp"
#include "command/add/add_command.hpp"
#include <iostream>

std::string	read_command(void)
{
	std::string	input;

	std::cout << "Enter a command: ";
	if (!std::getline(std::cin, input))
		exit(EXIT_FAILURE);
	return input;
}

void	execute_command(std::string &command, PhoneBook &phone_book)
{
	if (command == "ADD")
		write_new_contact(phone_book);
	else if (command == "SEARCH")
		phone_book.list_contacts();
}
