#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon request", 25, 5)
{
	target = "default";
	std::cout << "PresidentialPardonForm default constructor is used\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string initTarget) : AForm("PresidentialPardon request", 25, 5)
{
	target = initTarget;
	std::cout << "PresidentialPardonForm constructor is used\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &source) : AForm("PresidentialPardon request",
	source.getSignGrade(), source.getExecuteGrade())
{
	target = source.target;
	std::cout << "PresidentialPardonForm copy constructor is used\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
	target = source.target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	else if (!this->isSigned())
		throw (UnsignedFormException());
	else
		std::cout << target + " has been pardoned by Zaphod Beeblebrox\n";
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor is used\n";
}
