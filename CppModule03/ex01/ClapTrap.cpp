/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:12:52 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:12:58 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap( void )
{
	this->name = "BOTS";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout<<"ClapTrap Default constructor called"<<std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->name = name;
	this->hitPoints = 10;//health
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout<<"ClapTrap Parameter constructor called"<<std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &obj)
{
	*this = obj;
	std::cout<<"ClapTrap Copy constructor called"<<std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap const &obj)
{
	std::cout<<"ClapTrap assignment operator called"<<std::endl;
	if (this != &obj)
	{
		// this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout<<"ClapTrap Destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout<<"ClapTrap "<< this->name;
	std::cout<<" attacks " << target <<" causing ";
	if (hitPoints > 0 && this->energyPoints > 0)
	{
		this->energyPoints--;
		std::cout<<this->attackDamage<< " points of damage!"<<std::endl;
	}
	else
		std::cout<<" 0 "<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout<< "ClapTrap " << this->name << " take Damage ";
 	if (this->hitPoints > 0 && energyPoints > 0)
	{
		if (hitPoints < amount)
			 amount = this->hitPoints;
		this->hitPoints -= amount;
		std::cout<< amount <<" count "<<std::endl;
	}
	else
		std::cout<<" but have not hitPoints or energyPoints "<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout<<"ClapTrap "<< this->name;
	std::cout<< " be Repaired ";
	if (energyPoints > 0 && hitPoints > 0)
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout<< " causing "<< amount <<" hit point back "<<std::endl;
	}
	else
		std::cout<<" but have not hitPoints or energyPoints "<<std::endl;
}

//---------------------------------  get();  set();  -----------------------------------------

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->attackDamage = attackDamage;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return attackDamage;
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

std::string ClapTrap::getName(void) const
{
	return this->name;
}
