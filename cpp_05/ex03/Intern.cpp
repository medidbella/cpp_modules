#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "intern default constructor used\n";
	knownTypes[0] = "PresidentialPardon request";
	knownTypes[1] = "robotomy request";
	knownTypes[2] = "Shrubbery request";
}

Intern::Intern(const Intern &source)
{
	std::cout << "intern copy constructor used\n";
	for (int i = 0; i<3;i++)
		knownTypes[i] = source.knownTypes[i];
}

AForm *Intern::makeForm(std::string formType, std::string target)const
{
	int index = 0;
	while (index < 3 && knownTypes[index] != formType)	
		index++;
	switch (index)
	{
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
	}
	std::cerr << formType + " type is not know\n";
	return NULL;
}

Intern  &Intern::operator=(const Intern &source)
{
	for (int i = 0; i<3;i++)
		knownTypes[i] = source.knownTypes[i];
	return *this;
}

Intern::~Intern()
{

}
