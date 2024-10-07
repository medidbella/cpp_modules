#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>
#include <iostream>
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

#endif