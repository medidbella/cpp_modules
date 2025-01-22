#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery request", 145, 137)
{
	target = "default";
	std::cout << "ShrubberyCreationForm default constructor is used\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string initTarget) : AForm("Shrubbery request", 145, 137)
{
	target = initTarget;
	std::cout << "ShrubberyCreationForm constructor is used\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &source) : AForm("Shrubbery request", source.getSignGrade(),
	 source.getExecuteGrade())
{
	target = source.target;
	std::cout << "ShrubberyCreationForm copy constructor is used\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	target = source.target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::string fileName;
	if (executor.getGrade() > getExecuteGrade())
		throw (GradeTooLowException());
	else if (!this->isSigned())
		throw (UnsignedFormException());
	fileName = target + "_shrubbery";
	std::ofstream outFile(fileName.c_str());
	if (outFile.bad())
	{
		std::cout << "failed to open " + fileName + " for writing\n";
		return ;
	}
	std::string trees[3];
	trees[0] = 
	"		      	   ,@@@@@@@, \n\
	       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
	    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
	   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
	   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
	   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
	   `&%\\ ` /%&'    |.|        \\ '|8'\n\
	       |o|        | |         | |\n\
	       |.|        | |         | |\n\
	    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

	trees[1] = 
	"		      ccee88oo\n\
		    8ooo8888ooo8888o\n\
		  C8O8O8Q8PoOb o8oo\n\
		 dOB69QO8PdUOpugoO9bD\n\
		CgggbU8OU qOp qOdoUOdcb\n\
		    6OuU  /p u gcoUodpP\n\
		      \\\\//  /douUP\n\
		        \\\\////\n\
		         |||||\n\
		         |||\\/\n\
		         |||||\n\
		   .....//||||\\....\n";

	trees[2] = 
	"          		 @  @  @\n\
              @ @ @  @ @ @\n\
            @  @\\/@ @ /__@\n\
            @@@ @\\ / @/  @ @\n\
           @\\  \\/@| @ | @\n\
          @__\\@ \\ |/ \\| / @\n\
             __\\|@|  ||/__/@\n\
            /  \\ \\  / /__\n\
           @    \\  \\/ /   @\n\
                 |\"  |\n\
                 |\"  |\n\
                 |\"  |\n\
                ~|\"  |~\n\
            ~~~~       ~~~~\n\
          ~~               ~~~\n";
	std::srand(std::time(0));
	outFile << trees[std::rand() % 3];
	outFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor is used\n";
}
