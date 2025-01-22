#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm &source);
		RobotomyRequestForm(const std::string initTarget);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
		void execute(const Bureaucrat &executor) const;
		~RobotomyRequestForm();
};

#endif