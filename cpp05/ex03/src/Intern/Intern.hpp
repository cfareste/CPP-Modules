#pragma once

#define FORMS_COUNT 3
#define ROBOTOMY_REQUEST "robotomy request"
#define SHRUBBERY_CREATION "shrubbery creation"
#define PRESIDENTIAL_PARDON "presidential pardon"

#include "AForm/AForm.hpp"
#include <string>

class Intern {
	private:
		std::string	forms_name[3];
		AForm		*(Intern::*make_forms_ptrs[3])(const std::string &target);

		AForm	*makeRobotomyRequestForm(const std::string &target);
		AForm	*makeShrubberyCreationForm(const std::string &target);
		AForm	*makePresidentialPardonForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern &intern);

		AForm	*makeForm(const std::string &form_name, const std::string &target);

		Intern	&operator=(const Intern &intern);

		~Intern();
};
