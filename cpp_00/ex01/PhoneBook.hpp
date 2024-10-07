# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook{
	private:
		int oldest;
		int count;
		Contact memory[8];

	public:
		PhoneBook();
		void add_contact();
		void search();
};

#endif