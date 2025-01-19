#ifndef BUREAUCRAT
#define BUREAUCRAT

#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <iostream>
#include "Form.hpp"

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
		void signForm(Form &FormToSign) const;
};

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &data);

#endif