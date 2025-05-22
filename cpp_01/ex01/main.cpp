#include "Zombie.hpp"

int main()
{
	Zombie *Horde = zombieHorde(10, "frank");
	int		i = 0;
	while(i < 10)
	{
		Horde[i].announce();
		i++;
	}
	delete [] Horde;
}