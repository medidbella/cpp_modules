#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

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
};

template <typename iter>
void Span::addRange(iter begin, iter end)
{
	if (end - begin > emptyBlocks)
		throw 1;//throw a proper exception later
	Numbers.assign(begin, end);
	std::sort(Numbers.begin(), Numbers.end());
}

#endif