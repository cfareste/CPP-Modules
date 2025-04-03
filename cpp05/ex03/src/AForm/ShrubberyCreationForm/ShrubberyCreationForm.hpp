#pragma once

#include "AForm/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

		ShrubberyCreationForm();

		void	execute_concrete_form() const;

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &scf);

		~ShrubberyCreationForm();
};
