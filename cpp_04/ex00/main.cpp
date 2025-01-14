#include "Cat.hpp"
#include "Dog.hpp"


void test(Animal &ref){
	std::cout << ref.getType() << "\n";
	ref.makeSound();
}

int main()
{
	{
		Cat CatObj;
		CatObj.makeSound();
		test(CatObj);
	}
	{
		Dog dogObj;
		dogObj.makeSound();
		test(dogObj);
	}
	{
		Animal obj;
		obj.makeSound();
		test(obj);
	}
	// {
	// 	const Animal* meta = new Animal();
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
	// 	std::cout << j->getType() << "\n";
	// 	std::cout << i->getType() << "\n";
	// 	std::cout << meta->getType() << "\n";
	// 	i->makeSound();
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	delete meta;
	// 	delete j;
	// 	delete i;
	// }
	// {
	// 	const Animal &meta = Animal();
	// 	const Animal &j = Dog();
	// 	const Animal &i = Cat();
	// 	std::cout << j.getType() << " \n";
	// 	std::cout << i.getType() << " \n";
	// 	std::cout << meta.getType() << " \n";
	// 	i.makeSound();
	// 	j.makeSound();
	// 	meta.makeSound();
	// }
}