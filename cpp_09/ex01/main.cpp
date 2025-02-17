#include "RPN.hpp"
#include <stack>

int main(int Argc, char **Argv)
{
	if (Argc != 2){
		std::cout << "usage : ./RPN <reverse polish notation>"; return 1;}
	calculatePolishNotion(Argv[1]);
}
