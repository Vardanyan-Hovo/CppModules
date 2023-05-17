/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:09:29 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/04 14:48:05 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int value)
{
	std::cout<<"Parameter constructor called"<<std::endl;
	this->value = (value * (1 << this->fractional));
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = const_cast<Fixed&>(fixed);
}

Fixed& Fixed::operator=(Fixed &fixed)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this == &fixed)
	{
		return *this;
	}
	this->value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout<<"setRawBits member function called"<<std::endl;
	value = raw;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

const int Fixed::fractional = 8;