#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string 	name;
		bool 				_signed;
		const int			requiredSignGrade;
		const int 			requiredExecuteGrade;
	public:
		Form();
		Form(const Form &source);
		Form(std::string &initName, int signGrade, int executeGrade);
		std::string getName() const;
		bool isSigned() const;
		int	getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &worker);
		Form &operator=(const Form &source);
		~Form();
};

#endif