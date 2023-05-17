/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:39:15 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/30 18:43:01 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.hpp"


int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    return 0;
}

// int main()
// {
//     int x = 5, y = 4;
//     std::cout<<"Start  x = "<<x <<" y = "<<y <<std::endl;
//     ::swap(x, y);
//     std::cout<<"swap   x = "<<x <<" y = "<<y <<std::endl;
//     int mint = ::min<int>(x, y);
//     std::cout<<"min    x = "<<x <<" y = "<< y <<" min = "<<mint<<std::endl;
//     int maxt = ::max<int>(x, y);
//     std::cout<<"max    x = "<<x <<" y = "<< y <<" max = "<<maxt<<std::endl;
// }
