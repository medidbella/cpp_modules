#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor used\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = "empty";
}

Brain::Brain(const Brain &source)
{
	std::cout << "Brain copy constructor used\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = source.ideas[i];
}

Brain &Brain::operator=(const Brain &source)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = source.ideas[i];
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destructor used\n";
}