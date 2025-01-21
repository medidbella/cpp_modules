#include "AForm.hpp"

AForm::AForm() : name("unnamed") , requiredSignGrade(150),
	requiredExecuteGrade(150)
{
	std::cout << "AForm default constructor used\n";
	_signed = false;
}

AForm::AForm(const AForm &source) : name(source.name), 
	requiredSignGrade(source.requiredSignGrade),
		requiredExecuteGrade(source.requiredExecuteGrade)
{
	std::cout << "AForm copy constructor is used\n";
	_signed = source._signed;
}

AForm::AForm(const std::string &initName, int signGrade, int executeGrade) : name(initName),
	requiredSignGrade(signGrade), requiredExecuteGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 0 || executeGrade < 0)
		throw GradeTooHighException();
	std::cout << "AForm constructor is used\n";
	_signed = false;
}

void AForm::beSigned(const Bureaucrat &worker)
{
	if (worker.getGrade() > requiredSignGrade)
		throw worker.TooLowException;
	else
		_signed = true;
}

AForm &AForm::operator=(const AForm &source)
{
	_signed = source._signed;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const AForm &data)
{
	std::string msg = "not signed";
	if (data.isSigned())
		msg = "signed";
	stream << "AForm " + data.getName() + " is " + msg + ", grade to sign = " 
		<< data.getSignGrade() << " grade to execute = "
		<< data.getExecuteGrade() << '\n';
	return stream;
}

std::string AForm::getName() const {return name;}

bool AForm::isSigned() const {return _signed;}

int	AForm::getSignGrade() const {return requiredSignGrade;}

int AForm::getExecuteGrade() const {return requiredExecuteGrade;}

AForm::~AForm(){
	std::cout << "AForm destructor used\n";
}
