#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();
    //AAnimal* ani = new AAnimal("Animal");//

    std::cout << std::endl << "=== Make sound for dog and cat ===" << std::endl;
    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;

    delete dog;
    delete cat;

    return (0);
}