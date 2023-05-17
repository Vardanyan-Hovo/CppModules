/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:11:59 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:12:01 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout<<"FragTrap Default constructor called"<<std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout<<"FragTrap Parameter constructor called"<<std::endl;
}

FragTrap::FragTrap( FragTrap const &obj)
{
	*this = obj;
	std::cout<<"FragTrap Copy constructor called"<<std::endl;
}

FragTrap &FragTrap::operator=( FragTrap const &objs)
{
	std::cout<<"FragTrap assignment operator called"<<std::endl;
	if (this != &objs)
	{
		// this->name = obj.name;
		this->setHitPoints(objs.getHitPoints());
		this->setEnergyPoints(objs.getEnergyPoints());
		this->setAttackDamage(objs.getAttackDamage());
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout<<"FragTrap Destructor called"<<std::endl;
}

void FragTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

void FragTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

void FragTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}

unsigned int FragTrap::getHitPoints(void) const
{
	return (hitPoints);
}

unsigned int FragTrap::getEnergyPoints(void) const
{
	return energyPoints;
}

unsigned int FragTrap::getAttackDamage(void) const
{
	return attackDamage;
}

void FragTrap::setName(std::string name)
{
	this->name = name;
}

std::string FragTrap::getName(void) const
{
	return name;
}

void FragTrap::highFivesGuys(void)
{
	std::cout<< "FragTrap "<<this->getName() <<"  highFivesGuys "<<std::endl;
}
