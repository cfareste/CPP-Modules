#pragma once

#include "PhoneBook/PhoneBook.hpp"
#include <string>

class Application
{
	private:
		std::string	read_command(void);
		void	execute_command(std::string &command, PhoneBook &phone_book);

	public:
		Application();

		void	run();

		~Application();
};
