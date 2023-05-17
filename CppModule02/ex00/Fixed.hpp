/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:46:42 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/04 13:08:52 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(int);
		Fixed(Fixed const &);
		Fixed &operator=(Fixed &);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
	private:
		int value;
		static const int fractional;
};


#endif
