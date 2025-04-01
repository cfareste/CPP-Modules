#include "Form.hpp"

Form::Form() : name("Default"), sign_grade(1), execute_grade(1)
{
	this->is_signed = false;
}

Form::Form(const std::string &name, const int sign_grade, const int execute_grade):
	name(name),
	sign_grade(sign_grade),
	execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1) throw Form::GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150) throw Form::GradeTooLowException();

	this->is_signed = false;
}

Form::Form(const Form &form) : name(form.name), sign_grade(form.sign_grade), execute_grade(form.execute_grade)
{
	this->is_signed = form.is_signed;
}

const std::string	&Form::getName() const
{
	return this->name;
}

int	Form::isSigned() const
{
	return this->is_signed;
}

int	Form::getSignGrade() const
{
	return this->sign_grade;
}

int Form::getExecuteGrade() const
{
	return this->execute_grade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->sign_grade) throw Form::GradeTooLowException();

	this->is_signed = true;
}

Form	&Form::operator=(const Form &form)
{
	if (this == &form) return *this;

	this->is_signed = form.is_signed;
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const Form &form)
{
	stream << "Form " << form.getName() << ":\n"
		<< "Is signed: " << (form.isSigned() ? "yes\n" : "no\n")
		<< "Sign grade: " << form.getSignGrade() << "\n"
		<< "Execution grade: " << form.getExecuteGrade() << "\n";
	return stream;
}

Form::~Form()
{
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low, range [1, 150]";
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high, range [1, 150]";
}
