#include "Harl.hpp"

#include <iostream>

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		<< "I really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

Harl::Harl()
{
	this->complaints[0] = "DEBUG";
	this->complaints[1] = "INFO";
	this->complaints[2] = "WARNING";
	this->complaints[3] = "ERROR";
}

void Harl::complain(std::string level)
{
	int	i;

	for (i = 0; i < 4; i++)
		if (level == this->complaints[i]) break;

	switch (i)
	{
		case DEBUG_LEVEL:
			this->debug();
			//fallthrough
		case INFO_LEVEL:
			this->info();
			//fallthrough
		case WARNING_LEVEL:
			this->warning();
			//fallthrough
		case ERROR_LEVEL:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

Harl::~Harl()
{
}
