#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
}

void Zombie::announce( void )
{
	std::cout<<name<<": Moarbrainz...";
	std::cout<<std::endl;
}


