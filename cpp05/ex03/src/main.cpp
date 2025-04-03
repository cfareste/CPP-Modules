#include "Intern/Intern.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	bc = Bureaucrat("Chris", 1);
	Intern		intern = Intern();
	AForm		*forms[4];

	forms[0] = intern.makeForm("shrubbery creation", "target");
	forms[1] = intern.makeForm("presidential pardon", "target");
	forms[2] = intern.makeForm("fkjadkfj", "target");
	forms[3] = intern.makeForm("robotomy request", "target");

	for (int i = 0; i < 4; i++)
	{
		if (!forms[i])
		{
			std::cout << "No form was created" << std::endl;
			continue ;
		}
		bc.signForm(*forms[i]);
		bc.executeForm(*forms[i]);
		delete forms[i];
	}
	return 0;
}
