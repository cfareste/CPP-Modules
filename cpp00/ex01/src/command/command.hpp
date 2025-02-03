#pragma once

#include <string>
#include "PhoneBook/PhoneBook.hpp"

std::string	read_command(void);

void	execute_command(std::string &command, PhoneBook &phone_book);
