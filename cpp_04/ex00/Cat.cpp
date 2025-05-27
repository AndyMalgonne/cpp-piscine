#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->type = other.type;
	std::cout << "Cat copy constructor called for " << this->type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called for " << this->type << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = other.type;
	}
	std::cout << "Cat assignment operator called for " << this->type << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MIIIIAAAOOOUU" << std::endl;
}
