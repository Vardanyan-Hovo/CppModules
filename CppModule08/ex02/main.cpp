/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:13:11 by hvardany          #+#    #+#             */
/*   Updated: 2023/05/11 16:13:13 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.pop();
	mstack.pop();
	mstack.push(737);

	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	return 0;
}


// int main()
// {
// 	std::list<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << mstack.front() << std::endl;

// 	mstack.pop_back();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);

// 	mstack.pop_back();
// 	mstack.pop_back();
// 	mstack.push_back(737);

// 	mstack.push_back(0);

// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	// std::stack<int> s(mstack);
// 	return 0;
// }



// int main()
// {
// 	MutantStack<int> m;
// 	m.push(5);
// 	m.push(17);
// 	m.push(3);
// 	m.push(51);
// 	m.push(11);

// 	m.push(0);
// 	MutantStack<int> m_copy(m);
// 	MutantStack<int>::iterator it1 = m.begin();
// 	MutantStack<int>::iterator ite1 = m.end();
// 	std::cout<<"m1 = ";
// 	while (it1 != ite1)
// 	{
// 		std::cout << *it1 <<" ";
// 		++it1;
// 	}
// 	std::cout<< std::endl;
// 	MutantStack<int>::iterator it = m_copy.begin();
// 	MutantStack<int>::iterator ite = m_copy.end();
// 	std::cout<<"m2 = ";
// 	while (it != ite)
// 	{
// 		std::cout << *it << " ";
// 		++it;
// 	}
// 	std::cout<< std::endl;
// 	return 0;
// }
