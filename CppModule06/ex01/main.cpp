/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:29:34 by hvardany          #+#    #+#             */
/*   Updated: 2023/04/28 16:30:19 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    uintptr_t ui;
    Data *dafter;
    Data *dfirst = new Data(123);

    ui = Serializer::serialize(dfirst);
    dafter = Serializer::deserialize(ui);

    std::cout << dafter->getUi() << "               " << dfirst->getUi() <<std::endl;
    std::cout << dafter <<std::hex << "    " << ui << std::endl;
    return 0;
}
