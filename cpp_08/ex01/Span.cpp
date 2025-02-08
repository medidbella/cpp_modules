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
		throw Span::FullSpanException();
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
		throw Span::CalculationFailedException(ONE_ELEMENT_ERROR);
	std::vector<int> diffs(Numbers.size() - 1);
	std::transform(Numbers.begin() + 1, Numbers.end(), Numbers.begin(), diffs.begin(), get_span);
	std::sort(diffs.begin(), diffs.end());
	for (int i = 0; (unsigned)i < diffs.size(); i++)
		if (diffs[i] > 0)
			return diffs[i];
	throw Span::CalculationFailedException(REPEATED_ELEMENTS_ERROR);
}

int Span::longestSpan() const
{
	if (Numbers.size() < 2)
		throw Span::CalculationFailedException(ONE_ELEMENT_ERROR);
	if (Numbers[0] == Numbers[Numbers.size() - 1])
		throw Span::CalculationFailedException(REPEATED_ELEMENTS_ERROR);
	return (abs(Numbers[Numbers.size() - 1] - Numbers[0]));	
}

Span::FullSpanException::FullSpanException(){
	err = "attempt to add an element to a full span";
}

Span::FullSpanException::~FullSpanException() throw(){}

const char *Span::FullSpanException::what() const throw()
{
	return err.c_str();
}

Span::CalculationFailedException::CalculationFailedException(){
	err = "can't calculate the span";
}

Span::CalculationFailedException::CalculationFailedException(int errorFlag){
	if (errorFlag == ONE_ELEMENT_ERROR)
		err = "can't calculate the span : only one number in the span";
	else if (errorFlag == REPEATED_ELEMENTS_ERROR)
		err = "can't calculate the span : the span has one repeated number";
	else
		err = "can't calculate the span";
}

const char *Span::CalculationFailedException::what() const throw(){
	return err.c_str();
}

Span::CalculationFailedException::~CalculationFailedException() throw() {}

Span::~Span(){
	std::cout << "Span destructor used\n";
}