#pragma once

#include "Bureaucrat/Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			execute_grade;

		AForm();

	protected:
		virtual void	execute_concrete_form() const = 0;

	public:
		AForm(const std::string &name, const int sign_grade, const int execute_grade);
		AForm(const AForm &form);

		const std::string	&getName() const;
		int					isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		void				beSigned(const Bureaucrat &bureaucrat);

		void	execute(Bureaucrat const &executor) const;

		AForm	&operator=(const AForm &form);

		virtual ~AForm();

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};

		class FormNotSigned : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &form);
