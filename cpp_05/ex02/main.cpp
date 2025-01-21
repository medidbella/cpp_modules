#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test5() // AForm::execute unsigned Form test
{
	Bureaucrat worker("test3", 15);
	RobotomyRequestForm form1("execute_me");
	try {
		form1.execute(worker);
	}
	catch (UnsignedFormException &error){
		std::cout << "caught an exception : " 
			<< error.what() << '\n';
	}
}

void test4() // AForm::execute low grade Bureaucrat test
{
	Bureaucrat worker("test2", 150);
	PresidentialPardonForm form1("execute_me");
	try {
		form1.execute(worker);
	}
	catch (GradeTooLowException &error){
		std::cout << "caught an exception : " 
			<< error.what() << '\n';
	}
}

void test3() // AForm::execute test
{
	Bureaucrat worker("test2", 30);
	ShrubberyCreationForm form1("execute_me");
	form1.beSigned(worker);
	form1.execute(worker);
}

void test2()// unsigned forms grade test
{
	Bureaucrat junior("bob", 137);
	Bureaucrat senior("mark", 45);
	Bureaucrat manager("fred", 5);
	ShrubberyCreationForm form1("green");
	RobotomyRequestForm form2("robert");
	PresidentialPardonForm form3("robert");

	junior.executeForm(form1);
	senior.executeForm(form2);
	manager.executeForm(form3);
}

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

int main(int ac, char **av)
{
	void (*Tests[6])(void) = {test0, test1, test2, test3, test4, test5};
	int testNumber = 0;
	if (ac != 2){
		Tests[0]();
		return 0;
	}
	testNumber = std::atoi(av[1]);
	if (testNumber > 5 || testNumber < 0)
		testNumber = 0;
	Tests[testNumber]();
}