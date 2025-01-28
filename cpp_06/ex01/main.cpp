#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data mem;
	mem.member1 = 20;
	mem.member2 = 25;
	Data *ptr = Serializer::deserialize(Serializer::serialize(&mem));
	std::cout << (size_t)ptr << '\n' << (size_t)&mem << '\n';
	std::cout << ptr->member1 << ptr->member2 << '\n';
}