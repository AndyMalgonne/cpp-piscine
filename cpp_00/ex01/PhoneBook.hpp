#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>

class PhoneBook
{
	public:
		PhoneBook();
		void addContact();
		void searchContact();
	private:
		Contact contacts[8];
		int		counter;
		int		index;
};

#endif