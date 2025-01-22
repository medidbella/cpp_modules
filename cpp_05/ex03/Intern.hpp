#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		std::string knownTypes[3];
	public:
		Intern();
		Intern(const Intern &source);
		AForm *makeForm(std::string formType, std::string target)const;
		Intern  &operator=(const Intern &source);
		~Intern();
};

#endif