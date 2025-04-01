#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default")
{
	this->grade = 1;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();

	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name)
{
	this->grade = bureaucrat.grade;
}

const std::string	&Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade <= 1) throw Bureaucrat::GradeTooHighException();

	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade >= 150) throw Bureaucrat::GradeTooLowException();

	this->grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << this->name
			<< " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat) return *this;

	this->grade = bureaucrat.grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return stream;
}

Bureaucrat::~Bureaucrat()
{
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low, range [1, 150]";
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high, range [1, 150]";
}
