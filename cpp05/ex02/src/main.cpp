#include "AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	ShrubberyCreationForm	scf = ShrubberyCreationForm("Home");
	Bureaucrat				bc = Bureaucrat("Chris", 1);

	bc.signForm(scf);
	scf.execute(bc);
	return 0;
}
