/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:09:16 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/10 14:09:20 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap player[] = {ClapTrap("player0"), ClapTrap("player1"), ClapTrap("player2")};

	player[0].takeDamage(4);
	player[1].takeDamage(4);
	player[2].takeDamage(4);
	player[0].attack("player1");
	player[0].beRepaired(2);
	player[0].attack("player2");
	return 0;
}
