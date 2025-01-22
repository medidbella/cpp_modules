#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "ExcuteUnsigedFormException.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string 	name;
		bool 				_signed;
		const int			requiredSignGrade;
		const int 			requiredExecuteGrade;
	public:
		AForm();
		AForm(const AForm &source);
		AForm(const std::string &initName, int signGrade, int executeGrade);
		std::string getName() const;
		bool isSigned() const;
		int	getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &worker);
		virtual void execute(Bureaucrat const & executor) const = 0;
		AForm &operator=(const AForm &source);
		virtual ~AForm();
};

std::ostream &operator<<(std::ostream &stream, const AForm &data);

#endif