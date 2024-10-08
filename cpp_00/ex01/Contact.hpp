#pragma once
#include <iostream>
#include <string>

class Contact{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darckest_secret;

	public:
		int		set_members();
		void	display();
		void	print_row(int i);
};

