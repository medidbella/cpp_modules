# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook{
	private:
		int oldest;
		int count;

	public:
		Contact memory[3];

		PhoneBook();
		void add_contact();
		void search();
};

#endif