#include "Form.hpp"

Form::Form() : name("unnamed") , requiredSignGrade(150),
	requiredExecuteGrade(150)
{
	std::cout << "Form default constructor used\n";
	_signed = false;
}

Form::Form(const Form &source) : name(source.name), 
	requiredSignGrade(source.requiredSignGrade),
		requiredExecuteGrade(source.requiredExecuteGrade)
{
	std::cout << "Form copy constructor is used\n";
	_signed = source._signed;
}

Form::Form(std::string &initName, int signGrade, int executeGrade) : name(initName),
	requiredSignGrade(signGrade), requiredExecuteGrade(executeGrade)
{
	std::cout << "Form constructor is used\n";
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 0 || executeGrade < 0)
		throw GradeTooHighException();
	_signed = false;
}

void Form::beSigned(const Bureaucrat &worker)
{
	if (worker.getGrade() > requiredSignGrade)
		throw worker.TooLowException;
	else
		_signed = true;
}

Form &Form::operator=(const Form &source)
{
	_signed = source._signed;
	return *this;
}

std::string Form::getName() const {return name;}

bool Form::isSigned() const {return _signed;}

int	Form::getSignGrade() const {return requiredSignGrade;}

int Form::getExecuteGrade() const {return requiredExecuteGrade;}

Form::~Form(){
	std::cout << "Form destructor used\n";
}
