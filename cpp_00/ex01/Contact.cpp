#include "Contact.hpp"

void Contact::setFirstName(std::string firstName)
{
	this->FirstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->LastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	this->NickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->PhoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->DarkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
	return this->FirstName;
}

std::string Contact::getLastName()
{
	return this->LastName;
}
std::string Contact::getNickName()
{
	return this->NickName;
}
std::string Contact::getPhoneNumber()
{
	return this->PhoneNumber;
}
std::string Contact::getDarkestsecret()
{
	return this->DarkestSecret;
}