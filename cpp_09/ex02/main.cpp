#include "PmergeMe.hpp"

int main(int Argc, char **Argv)
{
	if (Argc != 2){
		std::cerr << "usage: " << Argv[0] << " <numbers>\n";
		return 1;
	}
	std::vector<int> vec;
	try{
		inputParser(vec, Argv[1]);
	}
	catch(std::exception &Error){
		std::cerr << Error.what() << "\n";
		return 1;
	}
	mergerInsertionSort(vec);
}