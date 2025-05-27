#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called for " << this->type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called for " << this->type << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal assignment operator called for " << this->type << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
