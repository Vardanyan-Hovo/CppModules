/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:12:39 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:12:42 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
	//---------------------------------  EnergyPoints = 100  --------------------------
	FragTrap player[] = {FragTrap("player0"), FragTrap("player1"), FragTrap("player2")};
	int i = 0;

	std::cout<<"getAttackDamage = "<<player[0].getAttackDamage()<<std::endl;
	std::cout<<"getEnergyPoints = "<<player[0].getEnergyPoints()<<std::endl;
	std::cout<<"getHitPoints    = "<<player[0].getHitPoints()<<std::endl;
	std::cout<<"getName         = "<<player[0].getName()<<std::endl;

	while (i < 102)
	{
		player[0].beRepaired(1);
		i++;
	}
	player[0].beRepaired(2);
	player[0].highFivesGuys();
	player[0].attack("player2");
	player[0].takeDamage(21);
	//-----------------------------------------------------
	std::cout<<std::endl<<std::endl;
	i = 0;
	player[2].attack("player2");
	player[2].beRepaired(2);
	std::cout<<std::endl<<std::endl;
	player[1].attack("player2");
	player[2].attack("player1");
	player[1].highFivesGuys();
	return 0;
}
