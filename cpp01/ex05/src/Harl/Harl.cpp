#include "Harl.hpp"

#include <iostream>

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put "
		<< "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. "
		<< "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	this->complains[0] = "DEBUG";
	this->complains[1] = "INFO";
	this->complains[2] = "WARNING";
	this->complains[3] = "ERROR";
	this->complain_behaviors[0] = &Harl::debug;
	this->complain_behaviors[1] = &Harl::info;
	this->complain_behaviors[2] = &Harl::warning;
	this->complain_behaviors[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->complains[i] == level)
			(this->*complain_behaviors[i])();
	}
}

Harl::~Harl()
{
}
