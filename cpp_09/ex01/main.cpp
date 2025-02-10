#include "RPN.hpp"
#include <stack>

int main(int Argc, char **Argv)
{
	if (Argc != 2){
		std::cerr << "./RPN <reverse polish notation >"; return 1;}
	calculatePolishNotion(Argv[1]);
}
