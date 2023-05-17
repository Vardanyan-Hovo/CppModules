#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:
		HumanB();
		HumanB(std::string name);
		HumanB(Weapon &weapon, std::string name);
		void setWeapon(Weapon &weapon);
		Weapon &getWeapon();
		~HumanB();
		void attack();
	private:
		std::string name;
		Weapon *weapon;
};

#endif
