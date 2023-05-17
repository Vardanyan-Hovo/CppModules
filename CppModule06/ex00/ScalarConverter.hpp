/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:34:57 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/28 15:49:42 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
// no static class in c++

class ScalarConverter
{
    public:
        //char  int float  double
        static void convert(const std::string &);
        static int  check_non_displayable(const std::string &s, bool &b);
        static void cout_func();
        static void cout_digit();
        static void float_check(const std::string &s);
        static void double_check(const std::string &s);
        static void int_check(const std::string &s);
        static void char_check(const std::string &s);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter &operator=(const ScalarConverter&);
        ~ScalarConverter();
        static int n_precision;
        static char c;//Non displayable
        static int i;//0
        static float f;//0.0f
        static double d;//0.0
        static int flags;//0 Non displayable
                        //1 int
                        //2 cahr
                        //3 float
                        //4 double
                        //5 nan
};


#endif
