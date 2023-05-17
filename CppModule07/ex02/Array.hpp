/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:43:52 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/30 18:47:11 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>
// #include <exception>


template<typename T>
class Array
{
    public:
        Array();
        Array(int n);
        Array(const Array<T>&a);
        Array<T> &operator=(const Array<T>&arr);
        T &operator[](int i);
        const T &operator[](int i) const;
        T *getApoint();
        unsigned int size(void) const;
        ~Array();
        class GradeExcep :public std::exception
        {
            public:
                GradeExcep();
				const char *what() const throw();
                GradeExcep(const char *s);
            private:
                const char *s;
        };
    private:
        T *a;
        unsigned int n;
};




#include "Array.tpp"

#endif
