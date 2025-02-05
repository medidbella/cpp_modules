#include "Span.hpp"

Span::Span()
{
	emptyBlocks = 0;
	std::cout << "used default constructor\n";
}

int get_span(int a, int b)
{
	return abs(a - b);
}

Span::Span(unsigned int initSize)
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
	std::vector<int> copy(Numbers.begin() + 1, Numbers.end());
	std::vector<int> diffs(copy.size());
	std::transform(copy.begin(), copy.end(), Numbers.begin(), diffs.begin(), get_span);
	std::sort(diffs.begin(), diffs.end());
	for (int i = 0; (unsigned)i < diffs.size(); i++)
		if (diffs[i] > 0)
			return diffs[i];
	throw 1;//....
}

int Span::longestSpan() const
{
	if (Numbers.size() < 2)
		throw 1;//...
	if (Numbers[0] == Numbers[Numbers.size() - 1])
		throw 1;//...
	return (abs(Numbers[Numbers.size() - 1] - Numbers[0]));
	
}

Span::~Span(){
	std::cout << "Span destructor used\n";
}