/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:13:33 by hvardany          #+#    #+#             */
/*   Updated: 2023/05/11 16:13:35 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>
#include <list>

template <class T , class Container = std::deque<T> >
class MutantStack :  public std::stack<T>
{
	public:

	typedef typename Container::iterator iterator;


	MutantStack() : MutantStack<T, Container>::stack(){};
	MutantStack(std::stack<T> &obj)
	{
		this->c = obj.getC();
	};
	MutantStack(std::list<T> &obj) : std::stack<T, Container>( obj )
	{
		this->c = obj.getC();
	};
	MutantStack<T, Container> & operator=(const MutantStack<T, Container> &obj)
    {
		if (this != &obj)
			std::stack<T>::operator=(obj);

		return *this;
	};
	Container getC();
	iterator begin();
	iterator end();
	~MutantStack(){};
};

#include "MutantStack.tpp"

#endif

