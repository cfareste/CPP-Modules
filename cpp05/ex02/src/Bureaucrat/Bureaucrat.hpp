#pragma once

#include "Form/Form.hpp"
#include <string>
#include <ostream>

class Form;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

		Bureaucrat();

	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);

		const std::string	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void	signForm(Form &form);

		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);

		~Bureaucrat();

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);
