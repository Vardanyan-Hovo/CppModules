#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *s;

	if (name.compare("") != 0)
	{
		s = new Zombie(name);
		return s;
	}
	std::cout<<"cannot create zombie";
	std::cout<<std::endl;
	return NULL;
}

