#include "Intern.hpp"
#include "Bureaucrat.hpp"

void test1() // unknown forms tests
{
	Intern newGuy;
	AForm *form1 = newGuy.makeForm("unvalid request", "target");
	AForm *form2 = newGuy.makeForm("unknow request", "target");
	AForm *form3 = newGuy.makeForm("request", "target");
	delete form1;
	delete form2;
	delete form3;
}

void test0()// general test
{
	Intern newGuy;
	AForm *form1 = newGuy.makeForm("PresidentialPardon request", "innocent guy");
	AForm *form2 = newGuy.makeForm("robotomy request", "someone");
	AForm *form3 = newGuy.makeForm("Shrubbery request", "green");
	std::cout << *form1 << *form2 << *form3;
	delete form1, delete form2, delete form3;
}

int main()
{
	test0();
	test1();
}