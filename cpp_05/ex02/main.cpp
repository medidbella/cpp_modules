#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test1()// low execute grade test
{
	Bureaucrat junior("bob", 145);
	Bureaucrat senior("mark", 72);
	Bureaucrat manager("fred", 25);
	ShrubberyCreationForm form1("green");
	RobotomyRequestForm form2("robert");
	PresidentialPardonForm form3("robert");

	junior.signForm(form1);
	senior.signForm(form2);
	manager.signForm(form3);

	junior.executeForm(form1);
	senior.executeForm(form2);
	manager.executeForm(form3);
}

void test0() // normal test
{
	Bureaucrat junior("bob", 137);
	Bureaucrat senior("mark", 45);
	Bureaucrat manager("fred", 5);
	ShrubberyCreationForm form1("green");
	RobotomyRequestForm form2("robert");
	PresidentialPardonForm form3("robert");

	junior.signForm(form1);
	senior.signForm(form2);
	manager.signForm(form3);

	junior.executeForm(form1);
	senior.executeForm(form2);
	manager.executeForm(form3);
}

int main()
{
	test1();
}