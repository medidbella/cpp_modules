#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{

	public:
		std::string ideas[100];
		Brain();
		Brain(const Brain &source);
		Brain &operator=(const Brain &source);
		~Brain();

};

#endif