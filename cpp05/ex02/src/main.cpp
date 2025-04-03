#include "AForm/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "AForm/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat				bc = Bureaucrat("Chris", 72);
	RobotomyRequestForm		rrf = RobotomyRequestForm("Bush");
	ShrubberyCreationForm	scf = ShrubberyCreationForm("Home");
	PresidentialPardonForm	ppf = PresidentialPardonForm("Tube");

	bc.signForm(scf);
	bc.signForm(rrf);
	bc.signForm(ppf);
	bc.executeForm(scf);
	bc.executeForm(rrf);
	bc.executeForm(ppf);

	bc = Bureaucrat("Chris", 1);

	bc.signForm(ppf);
	bc.executeForm(rrf);
	bc.executeForm(ppf);

	return 0;
}
