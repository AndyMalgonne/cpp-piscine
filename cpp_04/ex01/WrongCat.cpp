#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->type = other.type;
	std::cout << "WrongCat copy constructor called for " << this->type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called for " << this->type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->type = other.type;
	}
	std::cout << "WrongCat assignment operator called for " << this->type << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Weird Miaou Sound" << std::endl;
}
