#ifndef PMERGEME
#define PMERGEME

#include <deque>
#include <vector>
#include <iostream>
#include <sstream>
#include <exception>
#include <sys/time.h> 

class BadInputException : public std::exception
{
	private:
		std::string error;
	public:
		BadInputException(const std::string &err);
		BadInputException();
		const char *what() const throw();
		~BadInputException() throw();
};

int 		getInt(std::string &word);
size_t		getCurrentTime();
void 		mergerInsertionSort(std::vector<int> &input);
void		mergerInsertionSort(std::deque<int> &input);
void 		displayResults(std::deque<int> &sorted, size_t &deque_time,
				size_t &vector_time, char **unsorted_input);

template <typename T>
void inputParser(T &container, char **av)
{
	std::string number;
	for (int i = 0; av[i]; i++)
	{
		number = av[i];
		if (!number.empty())
			container.push_back(getInt(number));
	}
}

template <typename T>
void binarySearchInset(int element, T &container, int start, int end)
{
	if (end - start == 1 || end == start){
		typename T::iterator iter = container.begin();
		if (container[start] >= element)
			container.insert(iter+start, element);
		else if (container[end] <= element)
			container.insert(container.end(), element);
		else
			container.insert(iter+end, element);
		return ;
	}
	int mid = start + (end - start) / 2;
	if (element < container[mid])
		binarySearchInset(element, container, start, mid);
	else
		binarySearchInset(element, container, mid, end);
}

template <typename T>
void merge(T &mainContainer, T &left, T &right)
{
	unsigned int m = 0, r = 0, l = 0;

	while (m < mainContainer.size() && r < right.size() && l < left.size())
	{
		if (left[l] < right[r])
			mainContainer[m] = left[l++];
		else
			mainContainer[m] = right[r++];
		m++;
	}
	while (r < right.size())
		mainContainer[m++] = right[r++];
	while (l < left.size())
		mainContainer[m++] = left[l++];
}

template <typename T>
std::size_t SortingMonitor(T &container, char **input)
{
	std::size_t t0 = getCurrentTime();
	std::size_t t1;
	inputParser(container, input);
	mergerInsertionSort(container);
	t1 = getCurrentTime();
	return (t1 - t0);
}

#endif