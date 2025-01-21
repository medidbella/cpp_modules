#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &initName, int initGrade);
		Bureaucrat(const Bureaucrat &source);
		Bureaucrat &operator=(const Bureaucrat &source);
		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		GradeTooHighException TooHighException;
		GradeTooLowException TooLowException;
		~Bureaucrat();
		void signForm(AForm &FormToSign) const;
		void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &data);

#endif