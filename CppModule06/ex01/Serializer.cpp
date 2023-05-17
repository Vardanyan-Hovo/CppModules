/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:29:52 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/28 16:29:56 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer:: Serializer()
{
}

Serializer::~Serializer()
{
    
}
Serializer::Serializer(const Serializer&obj)
{
    (void)obj;
}

Serializer &Serializer::operator=(const Serializer &obj)
{
    (void)obj;
    return *this;
}
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *t;
    t = reinterpret_cast<Data*>(raw);
    return t;
}
