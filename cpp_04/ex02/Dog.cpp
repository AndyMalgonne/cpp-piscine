#include "Dog.hpp"

Dog::Dog() : AAnimal(), brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	this->type = other.type;
	std::cout << "Dog copy constructor called for " << this->type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for " << this->type << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called for " << this->type << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		this->type = other.type;
		if(this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
		for (int i = 0; i < 100; ++i)
		{
			this->brain->setIdea(i, other.brain->getIdea(i));
		}
	}
	return *this;
}
void Dog::makeSound() const
{
	std::cout << "Ouaf Ouaf" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}
