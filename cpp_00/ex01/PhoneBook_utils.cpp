#include "PhoneBook.hpp"
#include <string>
#include <sstream>
PhoneBook::PhoneBook(void){count = 0, oldest = 0;}

void	PhoneBook::add_contact(void)
{
	if (oldest < 3)
	{
		memory[oldest].set_members();
		oldest++;
		if (count < 3)
			count++;
	}
	else
		memory[0].set_members(), oldest = 1;
	return ;
}

void print_frame(void)
{
	std::cout << "--------------------------------------------\n";
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

void PhoneBook::search(void)
{
	if (count == 0)
	{
		std::cout << "phoneBook is empty\n";
		return ;
	}
	print_frame();
	for (int i = 0; i < count; i++)
	{
		std::string index;

		index[0] = i + 49;
		printer(index);
		printer(memory[i].first_name);
		printer(memory[i].last_name);
		printer(memory[i].nickname);
		std::cout << "|\n---------------------------------------------\n";
	}
}