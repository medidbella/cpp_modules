#include "Bureaucrat.hpp"
#include <cstdlib>

void test4()//test Form::beSigned method
{
	Bureaucrat worker("bob", 31);
	Form paper("report", 30, 31);
	std::cout << paper;
	try{
		paper.beSigned(worker);
	}
	catch (std::exception &exception){
		std::cout << paper.getName() << " could not be signed\n";
	}
	std::cout << paper;
}

void test3()//test invalid construction of Form (low grade)
{
	Form *formPtr;
	try {
		formPtr = new Form("paper", 45, 180);
	}
	catch(GradeTooLowException &err)
	{
		std::cout << err.what() << '\n';
		formPtr = new Form("paper", 150, 150);
	}
	std::cout << *formPtr;
}

void test2()// test invalid construction of Form (high grade)
{
	Form *formPtr;
	try {
		formPtr = new Form("paper", -1, 100);
	}
	catch(GradeTooHighException &err)
	{
		std::cout << err.what() << '\n';
		formPtr = new Form();
	}
	std::cout << *formPtr;
}

void test1() //test Bureaucrat::signForm method
{
	Bureaucrat manager("fred", 2);
	Form report("important report", 1, 10);
	std::cout << manager;
	std::cout << report;
	manager.signForm(report);
	manager.incrementGrade();
	std::cout << manager.getName() + "'s grade is incremented\n";
	manager.signForm(report);
	std::cout << report;
}

void test0() // general test
{
	Bureaucrat deskWorker("bob", 130);
	Form report("daily report", 130, 10);
	std::cout << deskWorker;
	std::cout << report;
	deskWorker.signForm(report);
	std::cout << report;
}

int main(int ac, char **av)
{
	void (*Tests[5])(void) = {test0, test1, test2, test3, test4};
	int testNumber = 0;
	if (ac != 2){
		Tests[0]();
		return 0;
	}
	testNumber = std::atoi(av[1]);
	if (testNumber > 4 || testNumber < 0)
		testNumber = 0;
	Tests[testNumber]();
}
