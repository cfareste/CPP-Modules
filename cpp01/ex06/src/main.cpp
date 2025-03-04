#include "Harl/Harl.hpp"

int	main(void)
{
	Harl	harl = Harl();

	harl.complain("UNKNOWN COMPLAIN");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("UNKNOWN COMPLAIN");
}
