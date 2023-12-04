/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:50:46 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/03 21:04:48 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string &Weapon::getType(void) {return _type;}

void Weapon::setType(std::string type) {_type = type;}

Weapon::Weapon(std::string type) {_type = type;}

Weapon::Weapon() {}

Weapon::~Weapon(void) {}

