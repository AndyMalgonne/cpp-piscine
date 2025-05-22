#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	while(1)
	{
		std::string input;

		if(std::cin.eof())
			break ;
		std::cout << "What do you want ? You can type add to save a new contact, search to display a specific contact and exit if you wanna abandon me" << std::endl;
		std::getline(std::cin, input);
		if(std::cin.eof())
			break ;
		if(input == "EXIT")
			break ;
		if(input == "ADD")
			phonebook.addContact();
		if(input == "SEARCH")
			phonebook.searchContact();
	}
}