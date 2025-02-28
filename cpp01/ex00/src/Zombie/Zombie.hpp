#pragma once

#include <string>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie(std::string name);

		void	announce();

		~Zombie();
};

Zombie	*newZombie(std::string);
void	randomChump(std::string);
