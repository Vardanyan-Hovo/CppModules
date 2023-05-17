/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:47:34 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/04 15:40:33 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::fractional = 8;

Fixed::Fixed():value(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int value)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->value = (value * (1 << this->fractional));
}

Fixed::Fixed(float value)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->value = roundf(value * (1 << fractional));
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(value)/(1 << fractional));
}

int Fixed::toInt( void ) const
{
	return (static_cast<int>(value)/(1 << fractional));
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = const_cast<Fixed&>(fixed);
}

std::ostream& operator<<(std::ostream &os_t, Fixed const &f)
{
	os_t<<f.toFloat();
	return os_t;
}
Fixed& Fixed::operator=(Fixed const &fixed)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this == &fixed)
	{
		return *this;
	}
	this->value = fixed.value;
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
