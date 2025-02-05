#include "Span.hpp"
#include <cstdlib>
template <typename iterator>
void randInit(iterator begin, iterator end, int rang)
{
	std::srand(time(0));
	while (begin != end + 1)
	{
		*begin = std::rand() % rang;
		begin++;
	}	
}

void test3()
{
	const int size = 10000;
	int arr[size];
	randInit(arr, arr + (size - 1), size + 1);
	Span mySpan(size);
	mySpan.addRange(arr, arr + (size - 1));
	std::cout << mySpan.longestSpan() << '\n';
	std::cout << mySpan.shortestSpan() << '\n';
}

void test2()
{
	const int size = 15;
	int arr[size];
	randInit(arr, arr + (size - 1), size + 1);
	for (int i = 0; i < size ;i++)
		std::cout << '[' << arr[i] << "] ";
	std::cout << '\n';
	Span mySpan(size);
	mySpan.addRange(arr, arr + (size - 1));
	std::cout << mySpan.longestSpan() << '\n';
	std::cout << mySpan.shortestSpan() << '\n';
}

void test1()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout  << '\n' << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	test3();
}
