#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &source);
		PresidentialPardonForm(const std::string newTarget);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
		void execute(const Bureaucrat &executor) const;
		~PresidentialPardonForm();
};

#endif