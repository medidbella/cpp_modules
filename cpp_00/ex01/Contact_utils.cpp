#include "Contact.hpp"

int	Contact::set_members(void)
{		
	std::cout << "Enter the new contact informations \n";
	std::cout << "first name : ";
	std::getline(std::cin, first_name);//should check if not empty
	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	std::cout << "nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "phone number : ";
	std::getline(std::cin, phone_number);
	std::cout << "darckest secret : ";
	std::getline(std::cin, darckest_secret);
	return 0;
}