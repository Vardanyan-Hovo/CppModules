/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:42:32 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/30 18:52:55 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void func(T const &b)
{
	std::cout<<"b = "<<b<<std::endl;
}


// template<typename T>
// void (*Func)(T &b);

template <typename T>
void iter( T *b, size_t len, void (*Func)(T const &b))
{
	for (size_t i = 0; i< len; i++)
	{
    	Func(b[i]);
	}
}

#endif
