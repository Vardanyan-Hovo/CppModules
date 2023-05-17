/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:48:42 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/04 15:41:09 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int);
		Fixed(float);
		Fixed(Fixed const &);
		Fixed &operator=(Fixed const &);

		int operator>(Fixed const &) const;
		int operator>(int i) const;
		int operator>(float i) const;

		int operator<(Fixed const &) const;
		int operator<(int i) const;
		int operator<(float i) const;

		int operator>=(Fixed const &) const;
		int operator>=(int i) const;
		int operator>=(float i) const;

		int operator<=(Fixed const &) const;
		int operator<=(int i) const;
		int operator<=(float i) const;

		int operator==(Fixed const &) const;
		int operator==(int i) const;

		int operator!=(Fixed const &) const;
		int operator!=(int i) const;
		int operator!=(float i) const;

		Fixed operator+(Fixed const &) const;
		Fixed operator+(int i) const;

		Fixed operator-(Fixed const &) const;
		Fixed operator-(int i) const;

		Fixed operator*(Fixed const &) const;
		Fixed operator*(int i) const;

		Fixed operator/(Fixed const &) const;
		Fixed operator/(int i) const;

		Fixed &operator++(void);
		Fixed operator++(int);

		Fixed &operator--(void);
		Fixed operator--(int);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		static Fixed& min(Fixed &f, Fixed &f1);
		static const Fixed&  min(Fixed const &f, Fixed const &f1);

		static Fixed & max(Fixed &f1, Fixed &f2);
		static const Fixed & max(Fixed const &f1, Fixed const &f2);

		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();
	private:
		int value;
		static const int fractional;
};

std::ostream& operator<<(std::ostream &ost, Fixed const &f);

Fixed & min(Fixed &f1 , Fixed &f2);
Fixed const & min(Fixed const &f1 , Fixed const &f2);
Fixed &max(Fixed &f1, Fixed &f2);
Fixed const& max(Fixed const &f1, Fixed const &f2);

int operator>(int i, Fixed const &f);
int operator<(int i, Fixed const &f);
int operator>=(int i, Fixed const &f);
int operator<=(int i, Fixed const &f);
int operator==(int i, Fixed const &f);
int operator!=(int i, Fixed const &f);
Fixed operator+(int i, Fixed const &f);
Fixed operator-(int i, Fixed const &f);
Fixed operator*(int i, Fixed const &f);
Fixed operator/(int i, Fixed const &f);


#endif
