#include "Bureaucrat.hpp"
#include <cstdlib>

void test1() //too low decrement grade test
{
	Bureaucrat acountnat("bob", 150);
	std::cout << acountnat;
	try{
		acountnat.decrementGrade();
	}
	catch (std::exception &exception){
		std::cout << exception.what() << '\n';
		std::cout << "exception caught, the Bureaucrat grade will remain the same\n";
	}
	std::cout << acountnat;
}

void test2() //too hight increment grade test
{
	Bureaucrat manager("mike", 1);
	try{
		manager.incrementGrade();
	}
	catch (GradeTooHighException &exception)
	{
		std::cout << exception.what() << '\n';
		std::cout << "exception caught, the Bureaucrat grade will remain the same\n";
	}
	std::cout << manager;
}

void test3() //too low grade in construction
{
	try{
		Bureaucrat director("someone", 160);
		std::cout << director;
	}
	catch (GradeTooLowException &err){
		std::cout << "failed to instantiate the Bureaucrat\n";
		std::cout << err.what() << '\n';
	}
}

void test4() //invalid grade in construction
{
	try{
		Bureaucrat director("someone", -1);
		std::cout << director;
	}
	catch (std::exception &err){
		std::cout << "failed to instantiate the Bureaucrat\n";
		std::cout << err.what() << '\n';
	}
}


void test0() //general test
{
	Bureaucrat test("test", 30);
	std::cout << "grade = " << test.getGrade() << "\n";
	std::cout << "name = " << test.getName() << "\n";
	test.decrementGrade();
	std::cout << "grade after using decrementGrade method = " << test.getGrade() << '\n';
	test.incrementGrade();
	std::cout << "grade after using incrementGrade method = " << test.getGrade() << '\n';
	std::cout << test;
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
