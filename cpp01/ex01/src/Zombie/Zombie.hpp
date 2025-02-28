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
