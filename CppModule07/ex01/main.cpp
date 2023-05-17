/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:42:42 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/30 18:42:44 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    std::string s[] = {"A","B", "C"};

    size_t lenarray = sizeof(array)/ sizeof(array[0]);
    size_t lenstring = sizeof(s)/ sizeof(s[0]);
    iter(array, lenarray, func);
    iter(s, lenstring, func);
}


// class Awesome
// {
// 	public:
// 		Awesome(void):_n(42){return ;}
// 		int get()const {return this->_n;}
// 	private:
// 		int _n;
// };


// std::ostream & operator<<(std::ostream & o, Awesome const &rhs){
// 	o<<rhs.get();
// 	return o;
// }

// template<typename T>
// void print(T const & x)
// {
// 	std::cout<<x<<std::endl;
// 	return ;
// }

// int main()
// {
// 	int tab[]={0,1,2,3,4};
// 	Awesome tab2[5];

// 	iter(tab , 5 , print);
// 	iter(tab2, 5, print);
// }
