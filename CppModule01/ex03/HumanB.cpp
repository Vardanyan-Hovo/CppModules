#include "HumanB.hpp"

HumanB::HumanB()
{

}

HumanB::HumanB(std::string name)
{
	this->name = name;
}
HumanB::HumanB(Weapon &weapon, std::string name)
{
	this->weapon = &weapon;
	this->name = name;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

Weapon &HumanB::getWeapon()
{
	return *weapon;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout<<name<< " attacks with their "<< (*weapon).getType()<<std::endl;
}

