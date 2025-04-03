#pragma once

#include "AForm/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

		PresidentialPardonForm();

		void	execute_concrete_form() const;

	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &scf);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &scf);

		~PresidentialPardonForm();
};
