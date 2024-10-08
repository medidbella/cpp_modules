#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void){count = 0, oldest = 0;}

void	PhoneBook::add_contact(void)
{
	if (oldest < 8)
	{
		if (memory[oldest].set_members())
			return ;
		oldest++;
		if (count < 8)
			count++;
	}
	else
	{
		if (memory[0].set_members())
			return ;
		oldest = 1;
	}
	return ;
}

void print_frame(void)
{
	std::cout << "---------------------------------------------\n";
	std::cout << "|     index|first_name| last_name|  nickname|\n";
	std::cout << "|__________|__________|__________|__________|\n";
}

void printer(std::string text)
{
	int size = text.size();
	int index = 0;
	int spaces = 10 - size;

	std::cout << "|";
	while (spaces-- > 0)
		std::cout << ' ';
	while (index < 9 && index < size)
		std::cout << text[index++];
	if (size > 10)
		std::cout << '.';
	else if (size == 10)
		std::cout << text[9];
	return ;
}

int format_check(std::string input)
{
	int j;
	int size = input.size();

	if (input.empty())
		return (std::cerr << "error: no input\n", 0);
	for (int i = 0; i < size; i++){
		if (!std::isdigit(input[i]))
			return (std::cerr << "error: index must be a digit\n", 0);
	}
	for (j = 0; j < size && input[j] == '0';)
		j++;
	if (j < size - 1)
		return (std::cerr << "error: Index is out of range\n", 0);
	return (1);
}

void PhoneBook::search(void)
{
	if (count == 0){
		std::cout << "phoneBook is empty\n";
		return ;
	}
	print_frame();
	for (int i = 0; i < count; i++)
	{
		std::cout << "|         " << (i + 1);
		printer(memory[i].first_name);
		printer(memory[i].last_name);
		printer(memory[i].nickname);
		std::cout << "|\n---------------------------------------------\n";
	}
	std::string input;
	std::cout << "chose a contact index to display: ";
	std::getline(std::cin, input);
	if (std::cin.eof()){
		std::cout << "\nEOF detected, exiting\n";
		exit(1);
	}
	if (format_check(input) == 0)
		return ;
	int index = std::atoi(input.c_str());
	if (index == 0){
		std::cerr << "error: Index must be greater that 0\n";
		return ;
	}
	if (index > count){
		std::cerr << "error: Index is out of range\n";
		return ;
	}
	memory[index - 1].display();
}
