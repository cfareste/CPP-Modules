#pragma once

#include <fstream>
#include <string>

class ClapTrap {
	private:
		std::string	name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;

		ClapTrap();

	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &ct);

		const std::string	&getName();
		int			getHitPoints();
		int			getEnergyPoints();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap	&operator=(const ClapTrap &ct);

		~ClapTrap();
};

std::ostream	&operator<<(std::ostream &stream, ClapTrap &clap_trap);
