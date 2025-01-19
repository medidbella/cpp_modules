#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknow")
{
	std::cout << "Bureaucrat default constructor is used\n";
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::string &initName, int initGrade) : name(initName)
{
	std::cout << "Bureaucrat constructor is used\n";
	if (initGrade > 150)
		throw TooLowException;
	else if (initGrade < 1)
		throw TooHighException;
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
	return *this;
}

int Bureaucrat::getGrade() const{
	return grade;
}

const std::string &Bureaucrat::getName() const{
	return name;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw TooHighException;
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw TooLowException;
	grade++;
}

void Bureaucrat::signForm(Form &FormToSign) const
{
	try{
		FormToSign.beSigned(*this);
	}
	catch (GradeTooLowException &exception){
		std::cout << name + " couldn't sign " + FormToSign.getName()
			<< " because his grade (" << grade
			<< ") is lower than the required sign grade ("
			<< FormToSign.getSignGrade() << ")\n";
	}
	std::cout << name + " Signed " + FormToSign.getName() << '\n';
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor is used\n";
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &data){
	stream << data.getName() + ", bureaucrat grade = " << data.getGrade() << ".\n";
	return stream;
}
