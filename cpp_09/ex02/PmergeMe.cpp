#include "PmergeMe.hpp"

BadInputException::BadInputException(){}

const char *BadInputException::what() const throw()
{
	return "Error";
}

BadInputException::~BadInputException() throw(){}

int getInt(std::string &word)
{
	std::stringstream ss(word);
	for (unsigned int i = 0; i < word.length(); i++){
		if (!std::isdigit(word[i]))
			throw BadInputException();
	}
	int res;
	ss >> res;
	if (res < 0)
		throw BadInputException();
	return res;
}

std::size_t getCurrentTime()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void inputParser(std::vector<int> &vec, char **av)
{
	std::string number;
	for (int i = 0; av[i]; i++)
	{
		number = av[i];
		if (!number.empty())
			vec.push_back(getInt(number));
	}
}

void mergeToVector(std::vector<int> &mainVec, std::vector<int> &left, std::vector<int> &right)
{
	unsigned int m = 0, r = 0, l = 0;

	while (m < mainVec.size() && r < right.size() && l < left.size())
	{
		if (left[l] < right[r])
			mainVec[m] = left[l++];
		else
			mainVec[m] = right[r++];
		m++;
	}
	while (r < right.size())
		mainVec[m++] = right[r++];
	while (l < left.size())
		mainVec[m++] = left[l++];
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

void binarySearchInset(int element, std::vector<int> &vec, int start, int end)
{
	
	if (end - start == 1 || end == start){
		std::vector<int>::iterator iter = vec.begin();
		if (vec[start] >= element)
			vec.insert(iter+start, element);
		else if (vec[end] <= element)
			vec.insert(vec.end(), element);
		else
			vec.insert(iter+end, element);
		return ;
	}
	int mid = start + (end - start) / 2;
	if (element < vec[mid])
		binarySearchInset(element, vec, start, mid);
	else
		binarySearchInset(element, vec, mid, end);
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
	mergeToVector(vec, largePart, smallPart);
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
