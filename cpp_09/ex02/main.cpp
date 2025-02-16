#include "PmergeMe.hpp"

int main(int Argc, char **Argv)
{
	if (Argc == 1){
		std::cerr << "usage: " << Argv[0] << " <numbers>\n";
		return 1;
	}
	std::vector<int> container1;
	std::deque<int> container2;
	std::size_t vector_time;
	std::size_t deque_time;
	try{
		vector_time = SortingMonitor(container1, Argv + 1);
		deque_time =  SortingMonitor(container2, Argv + 1);
	}
	catch(std::exception &Error){
		std::cerr << Error.what() << "\n";
		return 1;
	}
	displayResults(container2, deque_time, vector_time, Argv + 1);
}
