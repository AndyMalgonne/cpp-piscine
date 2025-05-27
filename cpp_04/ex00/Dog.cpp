#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Dog copy constructor called for " << this->type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for " << this->type << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
	}
	std::cout << "Dog assignment operator called for " << this->type << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf Ouaf" << std::endl;
}
