/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:11:09 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:11:12 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void) ;
		ScavTrap(const std::string& name);
		ScavTrap(ScavTrap const &);
		ScavTrap(const std::string&, int);
		ScavTrap &operator=(ScavTrap const &);
		virtual ~ScavTrap();
		void setHitPoints(unsigned int hitPoints);
		void setEnergyPoints(unsigned int energyPoints);
		void setAttackDamage(unsigned int attackDamage);
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;
		void setName(std::string name);
		std::string  getName(void) const;

	public:
		void attack(const std::string& target);
		void guardGate();
};

#endif
