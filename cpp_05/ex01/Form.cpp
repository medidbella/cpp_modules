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

Form::Form(const std::string &initName, int signGrade, int executeGrade) : name(initName),
	requiredSignGrade(signGrade), requiredExecuteGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 0 || executeGrade < 0)
		throw GradeTooHighException();
	std::cout << "Form constructor is used\n";
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

std::ostream &operator<<(std::ostream &stream, const Form &data)
{
	std::string msg = "not signed";
	if (data.isSigned())
		msg = "signed";
	stream << "Form " + data.getName() + " is " + msg + ", grade to sign = " 
		<< data.getSignGrade() << " grade to execute = "
		<< data.getExecuteGrade() << '\n';
	return stream;
}

std::string Form::getName() const {return name;}

bool Form::isSigned() const {return _signed;}

int	Form::getSignGrade() const {return requiredSignGrade;}

int Form::getExecuteGrade() const {return requiredExecuteGrade;}

Form::~Form(){
	std::cout << "Form destructor used\n";
}
