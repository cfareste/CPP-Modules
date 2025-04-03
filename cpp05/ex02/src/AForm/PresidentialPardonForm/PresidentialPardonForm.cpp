#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 1, 1)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf):
	AForm("Presidential Pardon Form", 25, 5)
{
	this->target = ppf.target;
}

void PresidentialPardonForm::execute_concrete_form() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
	if (this == &ppf) return *this;

	AForm::operator=(ppf);
	this->target = ppf.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
