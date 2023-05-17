/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:11:20 by hvardany          #+#    #+#             */
/*   Updated: 2023/05/11 16:11:25 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>

template<typename T>
typename T::iterator easyfind(T &v, int x)
{
	typename T::iterator it;

	it = std::find(v.begin(), v.end(), x);
	if (v.end() != it)
		return it;
	else
	  throw std::exception(); //	throw Exec();
	return it;
}



#endif

