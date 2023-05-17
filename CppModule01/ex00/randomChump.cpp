#include "Zombie.hpp"

void randomChump( std::string name )
{
	if (name.compare("") != 0)
	{
		Zombie ob(name);
		ob.announce();
	}
	else
	{
		std::cout<<"cannot create zombie"<<std::endl;
	}
}
