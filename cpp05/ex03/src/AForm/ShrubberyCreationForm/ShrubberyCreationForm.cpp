#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 1, 1)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf):
	AForm("Shrubbery Creation Form", 145, 137)
{
	this->target = scf.target;
}

void ShrubberyCreationForm::execute_concrete_form() const
{
	std::ofstream	target_file;

    target_file.open((this->target + "_shrubbery").c_str(), std::ios::trunc);
    if (!target_file.is_open())
		throw(std::runtime_error(std::string("Failed to open: ") + this->target + "_shrubbery"));

	for (int k = 1; k < 10; k += 3)
	{
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j <= 10 - i - k; j++)
				target_file << " ";
			for (int j = 0; j < (2 * (i + k - 1)) - 1; j++)
				target_file << "*";

			target_file << std::endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10 - 1; j++)
			target_file << " ";
		target_file << "|" << std::endl;
	}

	target_file.close();
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	if (this == &scf) return *this;

	AForm::operator=(scf);
	this->target = scf.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
