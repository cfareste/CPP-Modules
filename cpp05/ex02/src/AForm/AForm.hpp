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

	public:
		AForm(const std::string &name, const int sign_grade, const int execute_grade);
		AForm(const AForm &form);

		const std::string	&getName() const;
		int					isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		void				beSigned(const Bureaucrat &bureaucrat);

		virtual void	execute(Bureaucrat const &executor) = 0;

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
};

std::ostream	&operator<<(std::ostream &stream, const AForm &form);
