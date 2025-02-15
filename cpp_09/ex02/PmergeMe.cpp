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

void inputParser(std::vector<int> &vec, std::string input)
{
	std::stringstream ss(input);
	while (!ss.eof())
	{
		std::getline(ss, input, ' ');
		if (!input.empty())
			vec.push_back(getInt(input));
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

void recursiveSort(std::vector<int> &vec)
{
	if (vec.size() == 1)
		return ;
	int size = vec.size();
	std::vector< std::pair<int, int> > pairs(vec.size() / 2);
	int iter = 0;
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
	recursiveSort(largePart);
	recursiveSort(smallPart);
	mergeToVector(vec, largePart, smallPart);
}

void binarySearchInset(int element, std::vector<int> &vec, unsigned int start, unsigned int end)
{

}

void mergerInsertionSort(std::vector<int> &input)
{
	int lastElm = -1;
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
	for (unsigned int i =0 ; i < largePairNumbers.size(); i++)
		std::cout << largePairNumbers[i] << ' ';
	std::cout << '\n';
	recursiveSort(largePairNumbers);
//insert losers into winners

}
