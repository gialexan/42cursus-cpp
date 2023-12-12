/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:50:42 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 12:10:15 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void)
{
    std::cout << GREEN << _name << " attacks with their " << _weapon->getType() << std::endl << RESET;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
