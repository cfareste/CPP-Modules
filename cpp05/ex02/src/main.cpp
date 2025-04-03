#include "AForm/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "AForm/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat				bc = Bureaucrat("Chris", 1);
	RobotomyRequestForm		rrf = RobotomyRequestForm("Bush");
	ShrubberyCreationForm	scf = ShrubberyCreationForm("Home");
	PresidentialPardonForm	ppf = PresidentialPardonForm("Tube");

	bc.signForm(scf);
	bc.signForm(rrf);
	bc.signForm(ppf);

	scf.execute(bc);
	rrf.execute(bc);
	ppf.execute(bc);

	return 0;
}
