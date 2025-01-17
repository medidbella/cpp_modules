#include <iostream>

int main()
{
	std::string tab = "123";
	try
	{
		std::cout << tab.at(3) << std::endl;
	}
	catch (std::out_of_range& e){
		std::cout << "caught the exception\n";
	}
}