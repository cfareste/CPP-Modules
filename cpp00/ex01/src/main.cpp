#include "Contact/Contact.hpp"
#include "PhoneBook/PhoneBook.hpp"
#include "command/command.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	command = "";

	while (command != "EXIT")
	{
		command = read_command();
		execute_command(command, phone_book);
	}
	return 0;
}
