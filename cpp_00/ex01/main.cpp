#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	std::string input;
	PhoneBook  Awesome_phoneBook;

	std::cout << "PhoneBook started\n";
	std::cout << "you can use the commands: \"ADD\" ,\"SEARCH\" and \"EXIT\" \n";
	while (1)
	{
		std::cout << "\ncommand : ";
		std::getline(std::cin, input);
		if (!input[0] || input == "EXIT")
			return (0);
		else if (input == "ADD")
			Awesome_phoneBook.add_contact();
		else if (input == "SEARCH")
			Awesome_phoneBook.search();
		else
			std::cout << "\nunknown command\n";
	}
}
