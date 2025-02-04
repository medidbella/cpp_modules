#include "Span.hpp"

Span::Span()
{
	emptyBlocks = 0;
	std::cout << "used default constructor\n";
}

Span::Span(unsigned int initSize) : Numbers(initSize)
{
	emptyBlocks = initSize;
	std::cout << "used constructor\n";
}

void Span::addNumber(int newNum)
{
	if (emptyBlocks < 1)
		throw 1; //throw proper exception later
	emptyBlocks -= 1;
	Numbers.push_back(newNum);
	std::sort(Numbers.begin(), Numbers.end());
}

int Span::getSize() const
{
	return Numbers.size();
}

Span::Span(const Span &source)
{
	emptyBlocks = source.emptyBlocks;
	Numbers = source.Numbers;
}

Span &Span::operator=(const Span &source)
{
	emptyBlocks = source.emptyBlocks;
	Numbers = source.Numbers;
	return *this;
}

int Span::shortestSpan() const
{
	if (Numbers.size() < 2)
		throw 1;//throw ....
	int secondUniqueElementIndex = -1;
	for (int i = 1; i < Numbers.size(); i++)
	{
		if (Numbers[0] != Numbers[i])
		{
			secondUniqueElementIndex = i;
			break ;
		}
	}
	if (secondUniqueElementIndex == -1)
		throw 1;//....
	return (Numbers[0] - Numbers[secondUniqueElementIndex]);
}

int Span::longestSpan() const
{
	if (Numbers.size() < 2)
		throw 1;//...
	if (Numbers[0] == Numbers[Numbers.size() - 1])
		throw 1;//...
	return (Numbers[0] - Numbers[Numbers.size() - 1]);
	
}

Span::~Span(){
	std::cout << "Span destructor used\n";
}