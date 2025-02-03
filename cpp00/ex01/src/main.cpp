#include "Contact/Contact.hpp"
#include "PhoneBook/PhoneBook.hpp"
#include "command/command.hpp"

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
