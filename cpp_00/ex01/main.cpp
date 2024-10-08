#include "PhoneBook.hpp"

int main(void)
{
	std::string input;
	PhoneBook  Awesome_phoneBook;

	std::cout << "PhoneBook started\n\n";
	std::cout << "you can use the commands: \"ADD\" ,\"SEARCH\" and \"EXIT\" \n";
	while (1)
	{
		std::cout << "\ncommand : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (std::cout << "\nEOF detected, exiting\n", 1);
		if (input == "EXIT")
			return (std::cout << "exiting \n", 0);
		else if (input == "ADD")
			Awesome_phoneBook.add_contact();
		else if (input == "SEARCH")
			Awesome_phoneBook.search();
		else if (!input.empty())
			std::cerr << "\nerror: unknown command\n";
	}
}
