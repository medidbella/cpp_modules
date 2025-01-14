#include "Cat.hpp"
#include "Dog.hpp"


void test(Animal &ref){
	std::cout << ref.getType() << "\n";
	ref.makeSound();
}

int main()
{
	//test1
	{
		Cat CatObj;
		CatObj.makeSound();
		test(CatObj);
	}
	//test2
	{
		Dog dogObj;
		dogObj.makeSound();
		test(dogObj);
	}
	//test3
	{
		Animal obj;
		obj.makeSound();
		test(obj);
	}
	//test4
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << "\n";
		std::cout << i->getType() << "\n";
		std::cout << meta->getType() << "\n";
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	//test5
	{
		const Animal &meta = Animal();
		const Animal &j = Dog();
		const Animal &i = Cat();
		std::cout << j.getType() << " \n";
		std::cout << i.getType() << " \n";
		std::cout << meta.getType() << " \n";
		i.makeSound();
		j.makeSound();
		meta.makeSound();
	}
}