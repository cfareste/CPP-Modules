#include "AForm/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat				bc = Bureaucrat("Chris", 1);
	RobotomyRequestForm		rrf = RobotomyRequestForm("Bush");
	ShrubberyCreationForm	scf = ShrubberyCreationForm("Home");

	bc.signForm(scf);
	bc.signForm(rrf);

	scf.execute(bc);
	rrf.execute(bc);


	return 0;
}
