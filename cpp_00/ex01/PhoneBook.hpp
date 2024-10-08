#pragma once
#include "Contact.hpp"

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
