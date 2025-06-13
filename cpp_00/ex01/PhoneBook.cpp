#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->counter = 0;
    this->index = 0;
}


bool	isNumber(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool	isValidChar(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return false;
	}
	return true;
}


void PhoneBook::addContact()
{
    std::string input;

    while (true)
    {
        std::cout << "type the Firstname :";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return;
        if (!input.empty() && isValidChar(input))
            break;
        std::cout << "you have to type something in ..." << std::endl;
    }
    this->contacts[index].setFirstName(input);

    while (true)
    {
        std::cout << "type the Lastname :";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return;
        if (!input.empty() && isValidChar(input))
            break;
        std::cout << "you have to type something in ..." << std::endl;
    }
    this->contacts[index].setLastName(input);

    while (true)
    {
        std::cout << "type the Nickname :";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return;
        if (!input.empty() && isValidChar(input))
            break;
        std::cout << "you have to type something in ..." << std::endl;
    }
    this->contacts[index].setNickName(input);

    while (true)
    {
        std::cout << "type the Phone number :";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return;
        if (!input.empty() && isNumber(input))
            break;
        std::cout << "you have to type something in ..." << std::endl;
    }
    this->contacts[index].setPhoneNumber(input);

    while (true)
    {
        std::cout << "type the Darkest secret :";
        std::getline(std::cin, input);
        if (std::cin.eof())
            return;
        if (!input.empty() && isValidChar(input))
            break;
        std::cout << "you have to type something in ..." << std::endl;
    }
    this->contacts[index].setDarkestSecret(input);

    // Circular update logic
    index = (index + 1) % 8;
    if (counter < 8)
        counter++;

    std::cout << "Contact added successfully!" << std::endl;
    std::cout << "You can add another contact" << std::endl;
}


std::string formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    std::string res = str;
    while (res.length() < 10)
        res = " " + res;
    return res;
}

void	PhoneBook::searchContact()
{
    std::string input;
    int i = 0;

    if (this->counter == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return ;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|Index     |Firstname |Lastname  |Nickname  |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    while (i < this->counter)
    {
        std::cout << "|";
        std::cout.width(10);
        std::cout << i << "|";
        std::cout.width(9);
        std::cout << formatField(this->contacts[i].getFirstName()) << "|";
        std::cout.width(9);
        std::cout << formatField(this->contacts[i].getLastName()) << "|";
        std::cout.width(9);
        std::cout << formatField(this->contacts[i].getNickName()) << "|" << std::endl;
        i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Enter the index of the contact you want to see: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
        return ;
    int index = -1;
    if (input.length() == 1 && isdigit(input[0]))
        index = input[0] - '0';
    if (index < 0 || index >= this->counter)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    std::cout << "Firstname: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Lastname: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
    std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].getDarkestsecret() << std::endl;
}
