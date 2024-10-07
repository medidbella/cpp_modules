#include "Contact.hpp"
#include <cctype>
#include <cstdlib>

int is_all_space(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (isspace(str[i]))
			return (1);
	return (0);
}

int read_and_cheack(std::string &msg, std::string &temp)
{
	std::cout << msg;
	if (!std::getline(std::cin, temp)){
		std::cout << "\nEOF detected, exiting\n";
		exit(1);
	}
	if (temp.empty() || is_all_space(temp))
		return (1);
	return (0);
}

int	Contact::set_members(void)
{
	std::string temp[5];
	std::string msgs[5] = {"first name : ", "last name : ", "nickname : ",
						"phone number : ", "darckest secret : "};

	std::cout << "\nEnter the new contact informations \n\n";
	for (int i = 0; i < 5; i++){
		if (read_and_cheack(msgs[i], temp[i])){
			std::cerr << "\nerror: contacts can't have an empty field\n";
			return (1);
		}
	}
	first_name = temp[0];
	last_name = temp[1];
	nickname = temp[2];
	phone_number = temp[2];
	darckest_secret = temp[4];
	std::cout << "new contact added !\n";
	return (0);
}

void Contact::display(void)
{
	std::cout << "first_name = " << first_name << std::endl;
	std::cout << "last_name = " << last_name << std::endl;
	std::cout << "nickname = " << nickname << std::endl;
	std::cout << "phone_number = " << phone_number << std::endl;
	std::cout << "darckest_secret = " << darckest_secret << std::endl;
}
