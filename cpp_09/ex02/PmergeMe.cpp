#include "PmergeMe.hpp"

BadInputException::BadInputException(){}

BadInputException::BadInputException(const std::string &err){
	error = err;
}

const char *BadInputException::what() const throw()
{
	return error.c_str();
}

BadInputException::~BadInputException() throw(){}

int getInt(std::string &word)
{
	std::stringstream ss(word);
	for (unsigned int i = 0; i < word.length(); i++){
		if (!std::isdigit(word[i]))
			throw BadInputException("Bad Input");
	}
	int res;
	ss >> res;
	if (res < 0)
		throw BadInputException("negative number");
	return res;
}

std::size_t getCurrentTime()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void initParts(std::vector<int> &largeNbs, std::vector<int> &smallNbs,
	std::vector< std::pair<int, int> > &pairs)
{
	int iter = 0;
	for (unsigned int i = 0; i < pairs.size(); i++)
	{
		largeNbs[i] = pairs[iter].second;
		smallNbs[i] = pairs[iter].first;
		iter++;
	}
}

void initParts(std::deque<int> &largeNbs, std::deque<int> &smallNbs,
	std::deque< std::pair<int, int> > &pairs)
{
	int iter = 0;
	for (unsigned int i = 0; i < pairs.size(); i++)
	{
		largeNbs[i] = pairs[iter].second;
		smallNbs[i] = pairs[iter].first;
		iter++;
	}
}

void recursiveSort(std::vector<int> &vec)
{
	if (vec.size() == 1)
		return ;
	int size = vec.size();
	int lastElm = -1;
	std::vector< std::pair<int, int> > pairs(vec.size() / 2);
	int iter = 0;
	if (vec.size() % 2)
		lastElm = vec.back();
	for (unsigned int i = 0; i < vec.size() / 2; i++)
	{
		pairs[i].first = vec[iter++];
		pairs[i].second = vec[iter++];
	}
	for (unsigned int i = 0; i < pairs.size(); i++)
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	std::vector<int> smallPart(size / 2);
	std::vector<int> largePart(size / 2);
	initParts(largePart, smallPart, pairs);
	if(lastElm != -1)
		smallPart.push_back(lastElm);
	recursiveSort(largePart);
	recursiveSort(smallPart);
	merge(vec, largePart, smallPart);
}

void mergerInsertionSort(std::vector<int> &input)
{
	int lastElm = -1;
	if (input.size() == 1)
		return ;
	std::vector< std::pair<int, int> > pairs(input.size() / 2);
	std::vector<int> smallPairNumbers(input.size() / 2);
	std::vector<int> largePairNumbers(input.size() / 2);
	if (input.size() % 2)
		lastElm = input.back();
	int iter = 0;
	for (unsigned int i = 0; i < input.size() / 2; i++)
	{
		pairs[i].first = input[iter++];
		pairs[i].second = input[iter++];
	}
	for (unsigned int i = 0; i < pairs.size(); i++)
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	for (unsigned int i = 0; i < pairs.size(); i++)
	{
		smallPairNumbers[i] = pairs[i].first;
		largePairNumbers[i] = pairs[i].second;
	}
	recursiveSort(largePairNumbers);
	for(unsigned int i = 0; i < smallPairNumbers.size(); i++)
		binarySearchInset(smallPairNumbers[i], largePairNumbers, 0, largePairNumbers.size() - 1);	
	if (lastElm != -1)
		binarySearchInset(lastElm, largePairNumbers, 0, largePairNumbers.size() - 1);
	input = largePairNumbers;
	return ;
}

void recursiveSort(std::deque<int> &vec)
{
	if (vec.size() == 1)
		return ;
	int size = vec.size();
	int lastElm = -1;
	std::deque< std::pair<int, int> > pairs(vec.size() / 2);
	int iter = 0;
	if (vec.size() % 2)
		lastElm = vec.back();
	for (unsigned int i = 0; i < vec.size() / 2; i++)
	{
		pairs[i].first = vec[iter++];
		pairs[i].second = vec[iter++];
	}
	for (unsigned int i = 0; i < pairs.size(); i++)
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	std::deque<int> smallPart(size / 2);
	std::deque<int> largePart(size / 2);
	initParts(largePart, smallPart, pairs);
	if(lastElm != -1)
		smallPart.push_back(lastElm);
	recursiveSort(largePart);
	recursiveSort(smallPart);
	merge(vec, largePart, smallPart);
}

void mergerInsertionSort(std::deque<int> &input)
{
	int lastElm = -1;
	if (input.size() == 1)
		return ;
	std::deque< std::pair<int, int> > pairs(input.size() / 2);
	std::deque<int> smallPairNumbers(input.size() / 2);
	std::deque<int> largePairNumbers(input.size() / 2);
	if (input.size() % 2)
		lastElm = input.back();
	int iter = 0;
	for (unsigned int i = 0; i < input.size() / 2; i++)
	{
		pairs[i].first = input[iter++];
		pairs[i].second = input[iter++];
	}
	for (unsigned int i = 0; i < pairs.size(); i++)
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	for (unsigned int i = 0; i < pairs.size(); i++)
	{
		smallPairNumbers[i] = pairs[i].first;
		largePairNumbers[i] = pairs[i].second;
	}
	recursiveSort(largePairNumbers);
	for(unsigned int i = 0; i < smallPairNumbers.size(); i++)
		binarySearchInset(smallPairNumbers[i], largePairNumbers, 0, largePairNumbers.size() - 1);	
	if (lastElm != -1)
		binarySearchInset(lastElm, largePairNumbers, 0, largePairNumbers.size() - 1);
	input = largePairNumbers;
	return ;
}

void displayResults(std::deque<int> &sorted, size_t &deque_time,
	size_t &vector_time, char **unsorted_input)
{
	std::cout << "Before:  ";
	for (unsigned int i = 0;unsorted_input[i] ;i++)
	{
		std::cout << unsorted_input[i] << " ";
		if (i == 4){
			std::cout << "[...]";
			break;}
	}
	std::cout << "\nAfter:  ";
	for (unsigned int i = 0;i < sorted.size() ;i++)
	{
		std::cout << unsorted_input[i] << " ";
		if (i == 4){
			std::cout << "[...]";
			break;}
	}
	std::cout << "\nTime to process a range of " << sorted.size()
		<< " elements with std::vector : " << vector_time / 1000
			<< '.' << vector_time % 1000 << "\n";
	std::cout << "Time to process a range of " << sorted.size()
		<< " elements with std::deque : " << deque_time / 1000
			<< '.' << deque_time % 1000 << "\n";

}
