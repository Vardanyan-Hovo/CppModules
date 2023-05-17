/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:14:28 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:14:30 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap player[] = {ScavTrap("player0"), ScavTrap("player1"), ScavTrap("player2")};
	int i = 0;

	while (i < 51)
	{
		player[2].attack("player1");
		i++;
	}
	player[2].beRepaired(2);
	player[2].attack("player1");
	std::cout<<std::endl<<std::endl;
	i = 0;

	player[0].takeDamage(30);
	player[0].attack("player1");
	player[0].takeDamage(100);
	player[0].attack("player1");
	player[0].beRepaired(2);
	return 0;
}
