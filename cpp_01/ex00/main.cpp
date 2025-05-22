#include "Zombie.hpp"

int main()
{
	Zombie SuperZombie("Mick");
	Zombie SuperZombie2("Jean");

	SuperZombie.announce();
	randomChump("Alex");

	Zombie *Paul = newZombie("Paul");
	delete Paul;
}