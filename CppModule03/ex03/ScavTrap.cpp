/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:10:59 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:11:02 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout<<"ScavTrap Default constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout<<"ScavTrap Parameter constructor called"<<std::endl;
}

ScavTrap::ScavTrap(const std::string& name, int i): ClapTrap(name)
{
	i++;
	setEnergyPoints(50);
	std::cout<<"ScavTrap Parameter constructor called"<<std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &obj)
{
	*this = obj;
	std::cout<<"ScavTrap Copy constructor called"<<std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &objs)
{
	std::cout<<"ScavTrap assignment operator called"<<std::endl;
	if (this != &objs)
	{
		// this->name = obj.name;
		this->setHitPoints(objs.getHitPoints());
		this->setEnergyPoints(objs.getEnergyPoints());
		this->setAttackDamage(objs.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout<<"ScavTrap Destructor called"<<std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	std::cout<<" ScavTrap "<< this->getName();
	std::cout<<" attacks " << target <<" causing ";
	if (this->getHitPoints() > 0 && this->getEnergyPoints())
	{
		this->setHitPoints(getHitPoints() - 1);
		this->setEnergyPoints(getEnergyPoints() - 1);
		std::cout<<" 1 "<< " points of damage!"<<std::endl;
	}
	else
		std::cout<<" 0 "<<" points of damage!"<<std::endl;
}

void ScavTrap::guardGate()
{
   std::cout<<" ScavTrap " << this->getName() <<" Gate keeper mode "<<std::endl;
}




//----------------------------------------------------------- get; set-----------------


void ScavTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

void ScavTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ScavTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}

unsigned int ScavTrap::getHitPoints(void) const
{
	return (hitPoints);
}

unsigned int ScavTrap::getEnergyPoints(void) const
{
	return energyPoints;
}

unsigned int ScavTrap::getAttackDamage(void) const
{
	return attackDamage;
}

void ScavTrap::setName(std::string name)
{
	this->name = name;
}

std::string ScavTrap::getName(void) const
{
	return name;
}

