#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &src);
		~Animal();
		Animal& operator=(const Animal &src);
		void makeSound();
};
