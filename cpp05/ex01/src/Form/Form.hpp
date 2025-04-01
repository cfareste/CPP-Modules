#pragma once

#include "Bureaucrat/Bureaucrat.hpp"
#include <string>
#include <ostream>

class Form {
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			execute_grade;

		Form();

	public:
		Form(const std::string &name, const int sign_grade, const int execute_grade);
		Form(const Form &form);

		const std::string	&getName() const;
		int					isSigned() const;
		const int			getSignGrade() const;
		const int			getExecuteGrade() const;
		void				beSigned(const Bureaucrat &bureaucrat);

		Form	&operator=(const Form &form);

		~Form();

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const Form &form);
