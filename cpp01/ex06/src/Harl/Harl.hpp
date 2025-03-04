#pragma once

#define DEBUG_LEVEL 0
#define INFO_LEVEL 1
#define WARNING_LEVEL 2
#define ERROR_LEVEL 3

#include <string>

class Harl {
	private:
		std::string	complains[4];

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl();

		void	complain(std::string level);

		~Harl();
};
