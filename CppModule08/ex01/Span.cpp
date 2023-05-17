/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:11:57 by hvardany          #+#    #+#             */
/*   Updated: 2023/05/11 16:12:04 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n):N(n)
{
}

Span::Span(const Span &obj):N(obj.getN())
{
	std::vector<int> s = obj.getVec();
	if (N > 0)
	{
		am.assign(s.begin(),s.end());
	}
}

Span::Span(const Span *p):N(p->getN())
{
	std::vector<int> s = p->getVec();
	if (N > 0)
	{
		am.assign(s.begin(),s.end());
	}
}

Span & Span::operator=(const Span & obj)
{
	if (this != &obj)
	{
		std::vector<int> s = obj.getVec();
		N = obj.getN();
	   	if (N > 0)
		{
			am.assign(s.begin(),s.end());
		}
	}
	return *this;
}

Span::~Span()
{
}

// --------------------------- OrtConForm end-----

Span::Excp::Excp(const char *s)
{
	this->s = const_cast<char*>(s); 
}

const char *Span::Excp::what() const throw()
{
	return s;
}

std::vector<int> const &Span::getVec() const
{
	return am;
}

unsigned int Span::getN() const
{
	return N;
}

void Span::addNumber(int a)
{
	if (N <= am.size())
	{
		throw Span::Excp("trying to add new element, but olready N elements stored");
	}
	am.push_back(a);
	std::sort(am.begin(),am.end());
}

int Span::shortestSpan()
{
	int leng = 0;
	int flag = 0;

	if (am.size() <= 1)
		throw Span::Excp("The quantity of the element is not sufficient");
	for (std::vector<int>::iterator i = am.begin() + 1; i != am.end(); i++)
	{
		if (flag == 0)
		{
			leng = *i - *(i - 1);
			flag++;
		}
		if (leng > *i - *(i-1))
			leng = *i - *(i - 1);
	}
	return leng;
}

int Span::longestSpan()
{

	if (am.size() <= 1)
		throw Span::Excp("The quantity of the element is not sufficient");
	return am.back() - am.front(); 
}

void Span::test()
{
	int x;

	if (N < 10000 + am.size())
	{
		throw Span::Excp(" The number of elements plus 10,000 is greater than N");
	}
	for(int i = 0; i < 10000; i++)
	{
		x = rand() % 1500 + 1;
		x *= i % 5 ? -1 : 1;
		/*if (!(i % 20))
			std::cout<<std::endl;
		std::cout<<" "<<x;
		*/
		am.push_back(x);
	}
	std::sort(am.begin(), am.end());
}

