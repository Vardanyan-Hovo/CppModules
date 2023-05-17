/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <hvardany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:29:42 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/28 16:31:04 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP



#include <iostream>
#include <string>
#include "Data.hpp"

// class Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer&obj);
        Serializer &operator=(const Serializer &obj);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr); 
        static Data* deserialize(uintptr_t raw);
};

#endif
