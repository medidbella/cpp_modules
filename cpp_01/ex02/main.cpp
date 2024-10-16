#include <string>
#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string& stringREF = brain;

//  memeory addresses 
    std::cout << stringPTR << '\n';
    std::cout << &stringREF << '\n';
// values
    std::cout << *stringPTR << '\n';
    std::cout << stringREF << '\n';
}