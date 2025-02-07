#include <vector>
#include <iostream>
#include <deque>
#include "MutantStack.hpp"

void sub_test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout <<  "size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void test()
{
	MutantStack<std::string> newStack;
	newStack.push("one");
	newStack.push("two");
	newStack.push("three");
	newStack.push("four");
	newStack.push("five");
	MutantStack<std::string>::iterator iter = newStack.begin();
	do {
		std::cout << *iter << '\n';
		++iter;
	}
	while (iter != newStack.end());
	
}

int main()
{
	test();
}