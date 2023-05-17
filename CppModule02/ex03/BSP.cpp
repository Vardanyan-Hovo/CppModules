/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:49:06 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/04 15:57:36 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int BetaCheckZero(Point const &a, Point const &b , Point const &point)
{

	Fixed xa = a.getX();
	Fixed ya = a.getY();
	Fixed xb = b.getX();
	Fixed yb = b.getY();
	Fixed xpoint = point.getX();
	Fixed ypoint = point.getY();

	Fixed beta = (xb - xpoint) * (ya - ypoint) - (yb - ypoint) * (xa - xpoint);
	
	if (beta > 0)
		return 1;
	else if (beta < 0)
		return -1;
	return 0;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int vecto[3];

	vecto[0] = BetaCheckZero(b, a , point);
	vecto[1] = BetaCheckZero(a, c , point);
	vecto[2] = BetaCheckZero(c, b , point);
	if ((vecto[0] < 0) && (vecto[1] < 0) && (vecto[2] < 0))
		return true;
	if ((vecto[0] > 0) && (vecto[1] > 0) && (vecto[2] > 0))
		return true;
	return false;
}
