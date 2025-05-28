#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	this->type = other.type;
	std::cout << "Cat copy constructor called for " << this->type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called for " << this->type << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called for " << this->type << std::endl;

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

void Cat::makeSound() const
{
	std::cout << "MIIIIAAAOOOUU" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}