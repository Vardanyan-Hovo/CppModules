/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:50:30 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/04 15:58:10 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstring>

void printInitPoint(Point  (&f)[4],int i)
{
	std::cout<<"["<< i <<"]-----------------------------------------------"<<std::endl;
	if (bsp(f[0], f[1], f[2], f[3]) == true)
		{
			std::cout<<"   True: point is inside the triangle"<<std::endl;
		}
		else
			std::cout<<"   False: "<<std::endl;
	std::cout<<std::endl;
}

int main( void ) {

	Point f[4] = {Point(-4, -4), Point(-2.f, 6.f), Point(5,-2) , Point(7, 0)};	
	Point f1[4] = {Point(0.f, 0.f), Point(0.f, 0.f), Point(5,-2) , Point(7, 0)};
	Point f2[4] = {Point(-4.f, -4.f), Point(-2.f, 6.f), Point(5,-2) , Point(7, 0)};
	Point f3[4] = {Point(2.f, 0.5f), Point(6.f, 0.5f), Point(6.f,3.5f) , Point(5.f, 2.5f)};
	Point f4[4] = {Point(2.f, 0.5f), Point(6.f, 0.5f), Point(6.f,3.5f) , Point(6.f,3.5f)};
	Point f5[4] = {Point(2.0f, 0.5f), Point(0.0f, 0.f), Point(0.f,0.f) , Point(2.0f, 0.49f)};
	Point f6[4] = {Point(0,0), Point(0, 4), Point(5,0) , Point(1, 1)};
	Point f7[4] = {Point(-5.f,6.5f), Point(-8, 4), Point(-5.f,-3.5) , Point(-6.f, 0)};

	printInitPoint(f,0);
	printInitPoint(f1,1);
	printInitPoint(f2,2);
	printInitPoint(f3,3);
	printInitPoint(f4,4);
	printInitPoint(f5,5);
	printInitPoint(f6,6);
	printInitPoint(f7,7);

	return 0;
}

