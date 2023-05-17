/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:47:47 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/04 14:45:37 by hvardany         ###   ########.fr       */
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
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();
	private:
		int value;
		static const int fractional;
};

std::ostream& operator<<(std::ostream &ost, Fixed const &f);

#endif
