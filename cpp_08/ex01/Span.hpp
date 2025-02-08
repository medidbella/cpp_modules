#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

#define ONE_ELEMENT_ERROR 1
#define REPEATED_ELEMENTS_ERROR 2

class Span
{
	private:
		std::vector<int> Numbers;
		int emptyBlocks;
	public:
		Span();
		Span(unsigned int initSize);
		Span(const Span &source);
		Span &operator=(const Span &source);
		void addNumber(int newNum);
		int shortestSpan() const;
		int longestSpan()const;
		int getSize() const;
		template <typename iter>
		void addRange(iter begin, iter end);
		~Span();
		class FullSpanException : public std::exception
		{
			private:
				std::string err;
			public:
				FullSpanException();
				const char* what() const throw();
				~FullSpanException() throw();
		};
		class CalculationFailedException : public std::exception
		{
			private:
				std::string err;
			public:
				CalculationFailedException();
				CalculationFailedException(int errorFlag);
				const char *what() const throw();
				~CalculationFailedException() throw();
		};
};

template <typename iter>
void Span::addRange(iter begin, iter end)
{
	if (end - begin > emptyBlocks)
		throw Span::FullSpanException();//throw a proper exception later
	Numbers.assign(begin, end);
	std::sort(Numbers.begin(), Numbers.end());
}

#endif