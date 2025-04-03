#include "RobotomyRequestForm.hpp"
#include <cmath>
#include <iostream>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 1, 1)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rqf):
	AForm("Robotomy Request Form", 72, 45)
{
	this->target = rqf.target;
}

void RobotomyRequestForm::execute_concrete_form() const
{
	srand(getpid() * time(NULL));
	if ((rand() / (float) RAND_MAX) >= 0.5)
	{
		std::cout << "Robotomization failed. Address to your trusted MIT engineer" << std::endl;
		return ;
	}
	std::cout << this->target << " has been succesfully robotomized. Elon Musk approves" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rqf)
{
	if (this == &rqf) return *this;

	AForm::operator=(rqf);
	this->target = rqf.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
