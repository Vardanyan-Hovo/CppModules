/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:12:13 by hvardany          #+#    #+#             */
/*   Updated: 2023/05/11 16:12:18 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP


#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &obj);
		Span(const Span *p);
		Span &operator=(const Span &obj);
		~Span();
	public:
		class Excp : public std::exception
		{
			public:
				Excp(const char *s);
				virtual const char *what() const throw();
			private:
				char *s;
		};
		void addNumber(int a);
		void test();
		unsigned int getN() const;
		std::vector<int> const & getVec() const;
		int shortestSpan(); 
		int longestSpan();
	private:
		Span();
		unsigned int N;
		std::vector<int> am;
};

template<typename I>
void arraTest(I i, I end, Span &s)
{
	for ( ; i != end; i++)
	{
		s.addNumber(*i);
	}
}

#endif

