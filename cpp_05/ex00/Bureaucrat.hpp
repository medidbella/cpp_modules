#include <iostream>

class Bureaucrat{
	private:
		const	std::string name;
		int		grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string &initName, int initGrade);
		Bureaucrat(const Bureaucrat &source);
		Bureaucrat &operator=(const Bureaucrat &source);
		const std::string &getName();
		int getGrade();
		void incrementGrade();
		void decrementGrade();
		~Bureaucrat();
};