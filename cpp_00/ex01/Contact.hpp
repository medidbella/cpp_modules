#pragma once
#include <iostream>
#include <string>

class Contact{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darckest_secret;

		int		set_members();
		void	display();
};

