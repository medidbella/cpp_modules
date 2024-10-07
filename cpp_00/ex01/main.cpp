#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	std::string input;
	PhoneBook  Awesome_phoneBook;

	std::cout << "PhoneBook started\n\n";
	std::cout << "you can use the commands: \"ADD\" ,\"SEARCH\" and \"EXIT\" \n";
	while (1)
	{
		std::cout << "\ncommand : ";
		if (!std::getline(std::cin, input)){
			std::cout << "\nEOF detected, exiting\n";
			return (1);
		}
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			Awesome_phoneBook.add_contact();
		else if (input == "SEARCH")
			Awesome_phoneBook.search();
		else if (!input.empty())
			std::cerr << "\nerror: unknown command\n";
	}
}
