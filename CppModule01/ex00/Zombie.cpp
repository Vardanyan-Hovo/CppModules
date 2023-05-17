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
	std::cout<<this->name<<"	: DESTROYED"<<std::endl;
}

void Zombie::announce( void )
{
	std::cout<<name<<": BraiiiiiiinnnzzzZ...";
	std::cout<<std::endl;
}

