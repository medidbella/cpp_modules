#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &source);
		ShrubberyCreationForm(const std::string newTarget);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
		void execute(const Bureaucrat &executor) const;
		~ShrubberyCreationForm();
};

#endif