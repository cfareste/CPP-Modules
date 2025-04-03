#pragma once

#include "AForm/AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;

		RobotomyRequestForm();

		void	execute_concrete_form() const;

	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &scf);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &scf);

		~RobotomyRequestForm();
};
