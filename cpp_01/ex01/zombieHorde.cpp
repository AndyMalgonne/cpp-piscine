#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde = new Zombie[N];
	while (N > 0)
	{
		Horde[N-1].setName(name);
		N--;
	}
	return(Horde);
}
