/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:12:30 by hvardany          #+#    #+#             */
/*   Updated: 2023/05/11 16:12:33 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span (5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;	
	srand (time(NULL));
	try{
		Span snew(10100);
		snew.test();
		std::cout<<snew.shortestSpan()<<std::endl;
		std::cout << snew.longestSpan()<<std::endl;
		snew.addNumber(15);
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	try{
		Span *s1 = new Span(8);
		s1->longestSpan();
		delete s1;
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	try{
		Span *s2 = new Span(2);
		s2->addNumber(5);
		s2->addNumber(6);
		s2->addNumber(7);
		delete s2;
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	try{
		Span *s3 = new Span (1001);
		std::vector<int> arr(1000);
		std::generate(arr.begin(),arr.end(), rand);
		arraTest(arr.begin(),arr.end(), *s3);
		s3->addNumber(12);
		s3->addNumber(11);
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}
