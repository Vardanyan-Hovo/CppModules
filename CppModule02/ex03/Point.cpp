/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:49:49 by hvardany          #+#    #+#             */
/*   Updated: 2023/03/27 21:50:48 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0),y(0)
{
}

Point::Point(float const i, float const j):x(i),y(j)
{
}

Point::Point(const Point &other) : x(other.getFX()), y(other.getFY())
{
}

Point& Point::operator=(Point const &p)
{
	(void)p;
	return *this;
}

Point::~Point()
{
}

int Point::getX(void) const
{
	return x.toInt();
}

int Point::getY(void) const
{
	return y.toInt();
}
float	Point::getFX(void) const
{
	return (this->x.toFloat());
}

float	Point::getFY(void) const
{
	return (this->y.toFloat());
}
