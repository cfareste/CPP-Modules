#pragma once

#include <string>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie();
		Zombie(std::string name);

		void	set_name(std::string &name);

		void	announce();

		~Zombie();
};

Zombie	*zombieHorde(int n, std::string name);
