#pragma once

#include <string>

class Harl {
	private:
		std::string	complaints[4];
		void	(Harl::*complaint_behaviors[4])(void);

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();

		void	complain(std::string level);

		~Harl();
};
