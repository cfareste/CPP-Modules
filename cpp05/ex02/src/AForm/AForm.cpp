#include "AForm.hpp"

AForm::AForm() : name("Default"), sign_grade(1), execute_grade(1)
{
	this->is_signed = false;
}

AForm::AForm(const std::string &name, const int sign_grade, const int execute_grade):
	name(name),
	sign_grade(sign_grade),
	execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1) throw AForm::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150) throw AForm::GradeTooLowException();

	this->is_signed = false;
}

AForm::AForm(const AForm &form) : name(form.name), sign_grade(form.sign_grade), execute_grade(form.execute_grade)
{
	this->is_signed = form.is_signed;
}

const std::string	&AForm::getName() const
{
	return this->name;
}

int	AForm::isSigned() const
{
	return this->is_signed;
}

int	AForm::getSignGrade() const
{
	return this->sign_grade;
}

int AForm::getExecuteGrade() const
{
	return this->execute_grade;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade) throw AForm::GradeTooLowException();

	this->is_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned()) throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getExecuteGrade()) throw AForm::GradeTooLowException();

	this->execute_concrete_form();
}

AForm	&AForm::operator=(const AForm &form)
{
	if (this == &form) return *this;

	this->is_signed = form.is_signed;
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const AForm &form)
{
	stream << "Form " << form.getName() << ":\n"
		<< "Is signed: " << (form.isSigned() ? "yes\n" : "no\n")
		<< "Sign grade: " << form.getSignGrade() << "\n"
		<< "Execution grade: " << form.getExecuteGrade();
	return stream;
}

AForm::~AForm()
{
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low, range [1, 150]";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high, range [1, 150]";
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return "Form is not signed";
}
