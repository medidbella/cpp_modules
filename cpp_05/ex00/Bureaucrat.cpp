#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknow")
{
	std::cout << "Bureaucrat default constructor is used\n";
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string &initName, int initGrade) : name(initName)
{
	std::cout << "Bureaucrat constructor is used\n";
	// if (grade > 150 || grade < 1)
		//throw the exception
	grade = initGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{
	std::cout << "Bureaucrat copy constructor is used\n";
	grade = source.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "Bureaucrat copy assignment operator is used\n";
	grade = source.grade;
}

int Bureaucrat::getGrade(){
	return grade;
}

const std::string &Bureaucrat::getName(){
	return name;
}

void Bureaucrat::incrementGrade()
{
	// if (grade > 150 || grade < 150)
		// throw exception
	grade++;
}

void Bureaucrat::decrementGrade()
{
	// if (grade > 150 || grade < 150)
		// throw exception
	grade--;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor is used\n";
}
