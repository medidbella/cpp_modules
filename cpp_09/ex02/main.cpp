#include "PmergeMe.hpp"

int main(int Argc, char **Argv)
{
	if (Argc == 1){
		std::cerr << "usage: " << Argv[0] << " <numbers>\n";
		return 1;
	}
	std::size_t t0 = getCurrentTime();
	std::vector<int> vec(Argc - 1);
	try{
		inputParser(vec, Argv+1);
	}
	catch(std::exception &Error){
		std::cerr << Error.what() << "\n";
		return 1;
	}
	mergerInsertionSort(vec);
	std::size_t t1 = getCurrentTime();
	for (unsigned int i =0 ; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
	std::cout << "time to process " << Argc -1 << " elements using std::vector : " << t1 - t0 << "ms\n";
}