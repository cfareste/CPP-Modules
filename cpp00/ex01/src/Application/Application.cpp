#include "Application.hpp"
#include "PhoneBook/PhoneBook.hpp"
#include "command/command.hpp"

Application::Application()
{
}

void Application::run()
{
	PhoneBook	phone_book;
	std::string	command = "";

	while (command != "EXIT")
	{
		command = read_command();
		execute_command(command, phone_book);
	}
}

Application::~Application()
{
}
