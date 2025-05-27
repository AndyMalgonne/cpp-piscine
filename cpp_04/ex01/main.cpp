#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	Animal *animals[10];

	std::cout << "Start the creation of 10 animals" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;
	std::cout << "Animals created, let's listen to them:" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
		std::cout << "His type: " << animals[i]->getType() << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Start delete the 10 animals" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << "All animals are deleted" << std::endl;
	std::cout << std::endl;

	Dog dog1;
	Cat cat1;

	Brain* dogBrain = dog1.getBrain();
	Brain* catBrain = cat1.getBrain();

	dogBrain->setIdea(0, "I am a dog");
	catBrain->setIdea(0, "I am a cat");
	std::cout << std::endl;

	for (int i = 0; i < 110; i++)
	{
		dogBrain->setIdea(i, "I am a dog");
		catBrain->setIdea(i, "I am a cat");

	}
	std::cout << "Dog idea: " << dogBrain->getIdea(0) << std::endl;
	std::cout << "Cat idea: " << catBrain->getIdea(0) << std::endl;
	std::cout << "Dog idea: " << dogBrain->getIdea(-105) << std::endl;

	std::cout << std::endl;

	return 0;
}