#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

int is_all_space(std::string str)
{
	for (int i = 0; str[i]; i++)
		if (!isspace(str[i]))
			return (0);
	return (1);
}

int read_and_check(std::string &msg, std::string &temp)
{
	std::cout << msg;
	
	std::getline(std::cin, temp);
	if (std::cin.eof()){
		std::cout << "\nEOF detected, exiting\n";
		exit(1);
	}
	if (temp.empty() || is_all_space(temp))
		return (1);
	return (0);
}

void printer(std::string text)
{
	std::cout << '|';
	if (text.size() > 10)
		text = text.substr(0, 9) + ".";
	std::cout << std::setw(10);
	std::cout << text;
	return ;
}

int	Contact::set_members(void)
{
	std::string temp[5];
	std::string msgs[5] = {"first name : ", "last name : ", "nickname : ",
						"phone number : ", "darkest secret : "};

	std::cout << "\nEnter the new contact informations \n\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << msgs[i];
		std::getline(std::cin, temp[i]);
		if (std::cin.eof()){
			std::cout << "\nEOF detected, exiting\n";
			exit(1);
		}
		if (temp[i].empty() || is_all_space(temp[i]))
			return(std::cerr << "\nerror: contacts can't have an empty field\n", 1);
	}
	first_name = temp[0];
	last_name = temp[1];
	nickname = temp[2];
	phone_number = temp[3];
	darkest_secret = temp[4];
	std::cout << "new contact added !\n";
	return (0);
}

void Contact::display(void)
{
	std::cout << "first_name = " << first_name  + "\n";
	std::cout << "last_name = " << last_name  + "\n";
	std::cout << "nickname = " << nickname  + "\n";
	std::cout << "phone_number = " << phone_number  + "\n";
	std::cout << "darkest_secret = " << darkest_secret  + "\n";
}

void Contact::print_row(int i)
{
	std::cout << "|         " << (i + 1);
	printer(first_name);
	printer(last_name);
	printer(nickname);
	std::cout << "|\n---------------------------------------------\n";
}