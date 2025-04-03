#include "Intern.hpp"
#include "AForm/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "AForm/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "AForm/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	this->forms_name[0] = SHRUBBERY_CREATION;
	this->forms_name[1] = ROBOTOMY_REQUEST;
	this->forms_name[2] = PRESIDENTIAL_PARDON;
	this->make_forms_ptrs[0] = &Intern::makeShrubberyCreationForm;
	this->make_forms_ptrs[1] = &Intern::makeRobotomyRequestForm;
	this->make_forms_ptrs[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

AForm	*Intern::makeRobotomyRequestForm(const std::string &target)
{
	std::cout << "Intern creates Robotomy Request Form" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makeShrubberyCreationForm(const std::string &target)
{
	std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makePresidentialPardonForm(const std::string &target)
{
	std::cout << "Intern creates Presidential Pardon Form" << std::endl;
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target)
{
	for (int i = 0; i < FORMS_COUNT; i++)
	{
		if (this->forms_name[i] == form_name)
			return (this->*make_forms_ptrs[i])(target);
	}
	std::cout << "The form '" << form_name << "' doesn't exist" << std::endl;
	return NULL;
}

Intern	&Intern::operator=(const Intern &intern)
{
	if (this == &intern) return *this;

	for (int i = 0; i < FORMS_COUNT; i++)
	{
		this->forms_name[i] = intern.forms_name[i];
		this->make_forms_ptrs[i] = intern.make_forms_ptrs[i];
	}
	return *this;
}

Intern::~Intern()
{
}
