#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	std::srand(std::time(0));
	int number = std::rand() % 3;
	switch (number)
	{
		case 0:
			return new B();
		case 1:
			return new C();
		case 2:
			return new A();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<B*>(p))
		std::cout << "the pointer points to an instance of B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "the pointer points to an instance of C\n";
	else if ((dynamic_cast<A*>(p)))
		std::cout << "the pointer points to an instance of A\n";	
	else
		std::cout << "the pointer type is not known\n";
}

void identify(Base &p)
{
	if (dynamic_cast<B*>(&p))
		std::cout << "the reference points to an instance of B\n";
	else if (dynamic_cast<C*>(&p))
		std::cout << "the reference points to an instance of C\n";
	else if ((dynamic_cast<A*>(&p)))
		std::cout << "the reference points to an instance of A\n";	
	else
		std::cout << "the reference type is not known\n";
}

int main()
{
	Base *randomPtr = generate();
	identify(randomPtr);
	identify(*randomPtr);
	delete randomPtr;
}