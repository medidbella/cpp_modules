#pragma once
#include "Contact.hpp"
#define SIZE 8

class PhoneBook{
	private:
		int oldest;
		int count;
		Contact memory[SIZE];

	public:
		PhoneBook();
		void add_contact();
		void search();
};
