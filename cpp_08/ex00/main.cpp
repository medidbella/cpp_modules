#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"
#include <cstdlib>

void listTest()
{
	std::srand(time(0));
	std::list<int> myList;
	for (int i = 4; i > 0; i--)
		myList.push_back(std::rand() % 10);
	for (std::list<int>::iterator iter = myList.begin(); iter != myList.end();iter++)
		std::cout << '[' << *iter << "] ";
	std::cout << '\n';
	try
	{
		easyFind(myList, 7);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << '\n';
		return ;
	}
	std::cout << "lucky number found !\n"; 
}

void vectorTest()
{
	std::srand(time(0));
	std::vector<int> myVector(4);
	std::vector<int>::iterator iter = myVector.begin();
	for (;iter != myVector.end();iter++)
		*iter = std::rand() % 10;
	for (iter = myVector.begin(); iter != myVector.end();iter++)
		std::cout << '[' << *iter << "] ";
	std::cout << '\n';
	try
	{
		easyFind(myVector, 7);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << '\n';
		return ;
	}
	std::cout << "lucky number found !\n"; 
}

int main()
{
	listTest();
}