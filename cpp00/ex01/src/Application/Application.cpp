#include "Application.hpp"
#include "command/add/add_command.hpp"
#include <iostream>

Application::Application()
{
}

std::string	Application::read_command(void)
{
	std::string	input;

	std::cout << "Enter a command: ";
	if (!std::getline(std::cin, input))
		exit(EXIT_FAILURE);
	return input;
}

void	Application::execute_command(std::string &command, PhoneBook &phone_book)
{
	if (command == "ADD")
		write_new_contact(phone_book);
	else if (command == "SEARCH")
		phone_book.list_contacts();
}

void Application::run()
{
	PhoneBook	phone_book;
	std::string	command = "";

	while (command != "EXIT")
	{
		command = this->read_command();
		this->execute_command(command, phone_book);
	}
}

Application::~Application()
{
}
