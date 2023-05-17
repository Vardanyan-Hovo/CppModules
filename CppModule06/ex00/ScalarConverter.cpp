/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:34:36 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/28 15:56:25 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::flags = 0;
int ScalarConverter::i = 0;
float ScalarConverter::f = 0;
double ScalarConverter::d = 0;
char ScalarConverter::c = 0;
int ScalarConverter::n_precision = 0;

//     
ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    (void)obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter&obj)
{
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter()
{   
}

void ScalarConverter::cout_digit()
{
    if (i > 32 && i < 127)
        std::cout<<"char : " << c;
    else
        std::cout<<"char : Non displayable";
    std::cout<<std::endl;
    if (n_precision < 10)
    {
        std::cout << std::fixed;
        std::cout<<"int : " << i <<std::endl;
        std::cout<<"float : " <<std::setprecision(n_precision)  << f <<'f'<<std::endl;//
        std::cout<<"double : "<<std::setprecision(n_precision)  << d <<std::endl;
    }
    else
    {
        std::cout<<"int : " << i <<std::endl;
        std::cout<<"float : "  << f <<'f'<<std::endl;//
        std::cout<<"double : " << d <<std::endl;
    }
}

void ScalarConverter::cout_func()
{
    switch (flags)
    {
        case 0:
             std::cout<<"char: Non displayable\nint: 0 \nfloat: 0.0f\ndouble: 0.0"<<std::endl;
            break;
        case 1:
        case 3:
             cout_digit();
             break;
        case 5:
            std::cout<<"char: impossible\nint: impossible\nfloat: nanf\ndouble: nan"<<std::endl;
            break;
    };
}

int  ScalarConverter::check_non_displayable(const std::string &s, bool &b)
{
    size_t j = 0;
    size_t nu = 0;

    size_t k = s.find('.') != std::string::npos ? s.find('.')  : 0;
    if (s.find('f') != std::string::npos)
    {
        n_precision = s.find('f') - k - 1;
        b = 1;
    }
    else
    {
        n_precision = s.length() - k - 1;
        b = 0;
    }
    if (!s.compare("-inf") || !s.compare("-inff") || !s.compare("+inf") || !s.compare("+inff") 
        || !s.compare("nan"))
    {
        flags = 5;
        return 1;
    }
    if (isalpha(s[0]) && s.length() == 1)
    {
        flags = 1;
        return 0;
    }
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!(s[i]< 127 && s[i] > 31))
        {
            flags = 1;
            return 1;
        }
        if (((s[i] == '+' || s[i] == '-') && i == 0) ||isdigit(s[i]) || (s[i] == 'f' && !s[i + 1]) || (s[i]=='.' && s[i + 1] && isdigit(s[i + 1])))
        {
            if (s[i] == '0' || s[i] == 'f' || s[i] == '.'|| ((s[i] == '+' || s[i] == '-') && i == 0))
                nu++;
            j++;
        }
    }
    if (nu == s.length())
    {
        flags = 0;
        return 1;
    } 
    if (j != s.length() || s.find('.') != s.rfind('.'))
    {
        flags = 5;
        return 1;
    }
    return 0;
}


void ScalarConverter::int_check(const std::string &s)
{
    d = atof(s.c_str());
    if (d > INT_MAX || d < INT_MIN)
    {
        flags = 5;
        return ;
    }
    if (d > 0 && d < 127)
        c = static_cast<char>(d);
    f = static_cast<float>(d);
    flags = 3;
}

void ScalarConverter::float_check(const std::string &s)
{
    d = atof(s.c_str()); 
    if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
    {
        flags = 5;
        return ;
    }
    if (d > 0 && d < 127)
        c = static_cast<char>(d);
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    flags = 3;
}

void ScalarConverter::double_check(const std::string &s)
{
    d = atof(s.c_str());
    if (d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::min())
    {
        flags = 5;
        return ;
    }
    if (d > 0 && d < 127)
        c = static_cast<char>(d);
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    flags = 3;
}

void ScalarConverter::char_check(const std::string &s)
{
    c = s[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    flags = 1;
}
void ScalarConverter::convert(const std::string &s)
{
    bool base = 0;

    if (check_non_displayable(s, base) != 1)
    {
        if (isalpha(s[0]) && s.length() == 1)
        {
            char_check(s);
            flags = 1;
        }
        else if (!base && s.find('.') == std::string::npos)
        {
            n_precision = 1;
            int_check(s);
            i = static_cast<int>(d);
            flags = 3;
        }
        else if (!base && s.find('.') != std::string::npos)
            double_check(s);
        else if (base && s[s.find('f') + 1] == '\0')
            float_check(s);
        else
            flags = 5;
    }
    cout_func();
}
