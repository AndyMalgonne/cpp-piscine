#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called for " << this->type << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called for " << this->type << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "AAnimal assignment operator called for " << this->type << std::endl;
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal makes a sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}
