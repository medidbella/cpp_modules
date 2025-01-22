#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45)
{
	target = "default";
	std::cout << "RobotomyRequestForm default constructor is used\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string initTarget) : AForm("robotomy request", 72, 45)
{
	target = initTarget;
	std::cout << "RobotomyRequestForm constructor is used\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &source) : AForm("robotomy request", source.getSignGrade(),
	source.getExecuteGrade())
{
	target = source.target;
	std::cout << "RobotomyRequestForm copy constructor is used\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	target = source.target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	std::srand(std::time(0));
	if (executor.getGrade() > getExecuteGrade())
		throw (GradeTooLowException());
	else if (!this->isSigned())
		throw (UnsignedFormException());
	std::cout << "whGRrGRGRGRGGGGGggggrr...(drilling noise)\n";
	if (std::rand() % 2 == 0)
		std::cout << target + " has been robotomized successfully\n";
	else
		std::cout << "robotomy failed on " + target + "\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor is used\n";
}
