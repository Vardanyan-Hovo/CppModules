/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:37:14 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/28 16:37:18 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

//It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
//to use anything you like for the random choice implementation
Base * generate(void)
{
    // set seed to time(0)
    
    // generate random number
    int random = rand() % 3;
    switch(random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C"
void identify(Base* p)
{
    // std::cout<<"Type"<<std::endl;
    if (dynamic_cast<A*>(p) != NULL)
        std::cout<<"A"<<std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout<<"B"<<std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout<<"C"<<std::endl;
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
//inside this function is forbidden
void identify(Base&p)
{
    Base ps;

    for (size_t i = 0; i < 3; i++)
    {
       try
       {
        switch (i)
        {
        case 0:
           ps = dynamic_cast<A&>(p);
            std::cout<<"A"<<std::endl;
            break;
        case 1:
            ps = dynamic_cast<B&>(p);
             std::cout<<"B"<<std::endl;
            break;
        case 2:
            ps = dynamic_cast<C&>(p);
                std::cout<<"C"<<std::endl;
            break;
        }
       }
       catch(const std::exception& e)
       {
       }
    }
    (void)ps;
}


int main()
{
    srand(time(NULL));
    Base *D = generate();
    identify(D);
    D = generate();
    identify(*D);
    D = generate();
    identify(D);
    A *a = new A();
    B *b = new B();
    C *c = new C();

    identify(a);
    identify(b);
    identify(c);
    Base *a1 = new A();
    Base *b1 = new B();
    Base *c1 = new C();
    std::cout<<" when   &"<<std::endl;
    identify(*a1);
    identify(*b1);
    identify(*c1);
    return 0;
}
