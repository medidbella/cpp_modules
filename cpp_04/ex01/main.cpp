#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// //test1
	// {
	// 	const int size = 4;
	// 	Animal **pets = new Animal*[size];

	// 	for (int i = 0; i < size / 2; i++)
	// 		pets[i] = new Cat();
	// 	for (int i = size / 2; i < size; i++)
	// 		pets[i] = new Dog();
	// 	for (int i = 0; i < size; i++)
	// 		std::cout << "type of pets[" << i << "] = " << pets[i]->getType() << "\n";
	// 	for (int i = 0; i < size; i++)
	// 		delete pets[i];
	// 	delete[] pets;
	// }
	// //test2
	// {
	// 	Cat *cat = new Cat();
	// 	Dog *dog = new Dog();
	// 	delete cat;
	// 	delete dog;
	// }
	// // test3
	// {
	// 	Animal *generalPtr1 = new Cat();
	// 	Animal *generalPtr2 = new Dog();
	// 	delete generalPtr1;
	// 	delete generalPtr2;
	// }
	Dog basic;
	Dog tmp = basic;
}