#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Z;
	if (N > 0 && name.compare("") != 0)
	{
		Z = new Zombie[N];
		while(--N >= 0)
			Z[N] = name;
		return (Z);
	}
	return NULL;
}
