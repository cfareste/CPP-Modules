#pragma once

#include "AForm/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf);

		void	execute_concrete_form() const;

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &scf);

		~ShrubberyCreationForm();
};
