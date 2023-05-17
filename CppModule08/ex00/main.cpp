/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:11:31 by hvardany          #+#    #+#             */
/*   Updated: 2023/05/11 16:11:33 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

	int arr[] = {1,2,3,4,5,6};
	int n;
	std::vector<int> t; //= {5,8,1,0}; 11standart//  standart20
	t.push_back(5);
	t.push_back(8);
	t.push_back(1);
	t.push_back(0);
	t.push_back(4);
	n = sizeof(arr)/ sizeof(arr[0]);
	std::vector<int> v(arr, arr + n);
	int x = 4;
	try{
		std::cout<< *easyfind< std::vector<int> >(v, x)<<std::endl;
		std::cout<< *easyfind(t, 16)<<std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}
