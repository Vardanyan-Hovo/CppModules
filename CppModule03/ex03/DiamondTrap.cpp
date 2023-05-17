/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:09:43 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:10:00 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : name("robot")
{
	std::cout<<"DiamondTrap Default constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name),ScavTrap(name, 1)
{
	this->name = name;
	std::cout<<"DiamondTrap Parameter constructor called"<<std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &obj)
{
	*this = obj;
	std::cout<<"DiamondTrap Copy constructor called"<<std::endl;
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &objs)
{
	std::cout<<"DiamondTrap assignment operator called"<<std::endl;
	if (this != &objs)
	{
		// this->name = objs.getName() + "copy";
		this->setHitPoints(objs.getHitPoints());
		this->setEnergyPoints(objs.getEnergyPoints());
		this->setAttackDamage(objs.getAttackDamage());
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout<<"DiamondTrap Destructor called"<<std::endl;
}

//--------------------------- set --- get -----------------------

void DiamondTrap::attack(const std::string &name)
{
	this->ScavTrap::attack(name);
}

void DiamondTrap::whoAmI()
{
	std::cout<<" DiamondTrap name = "<<this->name<<std::endl;
	std::cout<<" ScavTrap    name = "<<this->ClapTrap::getName();
	std::cout<<std::endl;
}

void DiamondTrap::whoAmI1()
{
	std::cout<<" DiamondTrap name = "<<this->name<<std::endl;
	std::cout<<" ClapTrap    name = "<<this->FragTrap::ClapTrap::getName()<<std::endl;
	std::cout<<" ScavTrap    name = "<<this->ScavTrap::ClapTrap::getName()<<std::endl;
	std::cout<<" ScavTrap    name = "<<this->ClapTrap::getName();
	std::cout<<std::endl;
}

void DiamondTrap::setHitPoints(const unsigned int x)
{
	this->FragTrap::setHitPoints(x);
}

unsigned int DiamondTrap::getHitPoints(void) const
{
	return this->FragTrap::getHitPoints();
}

void DiamondTrap::setEnergyPoints(const unsigned int x)
{
	this->ScavTrap::setEnergyPoints(x);
}

unsigned int DiamondTrap::getEnergyPoints(void) const
{
	return this->ScavTrap::getEnergyPoints();
}

void DiamondTrap::setAttackDamage(const unsigned int x)
{
	this->FragTrap::setAttackDamage(x);
}

unsigned int DiamondTrap::getAttackDamage(void) const
{
	return this->FragTrap::getAttackDamage();
}

std::string DiamondTrap::getName(void) const
{
	return this->name;
}

void DiamondTrap::setName(const std::string &name)
{
	 this->name = name;
}
