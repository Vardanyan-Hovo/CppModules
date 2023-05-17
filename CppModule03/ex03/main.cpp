/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:11:17 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:11:20 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap s (DiamondTrap("Player"));
	s.attack("player2");
	s.whoAmI();
	s.beRepaired(2);

	std::cout<<std::endl<<std::endl<<std::endl;

	DiamondTrap d("PLAYER2");
	std::cout<<"name         = "<<d.getName()<<std::endl;
	std::cout<<"AttackDamage = "<<d.getAttackDamage()<<std::endl;
	std::cout<<"EnergyPoints = "<<d.getEnergyPoints()<<std::endl;
	std::cout<<"HitPoints    = "<<d.getHitPoints()<<std::endl;
	d.whoAmI();
	return 0;
}
