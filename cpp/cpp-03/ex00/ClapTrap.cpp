/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:52:27 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/16 20:34:20 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) 
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    _name = obj.getName();
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    *this = obj;
}

std::string ClapTrap::getName(void) const
{
    return _name;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "Energy Point: " << _energyPoints << " Hit Point: " << _hitPoints << std::endl;
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
    }
    else
        std::cout << _name << " can't attack " << target << ". He is already 💀 !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		std::cout << _name << " got repaired, and it has " << _hitPoints << " Hit Points now!" << std::endl;
	}
	else
		std::cout << _name << " can't take damge. He is already 💀 !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << _name << " take damage " << amount << ", and it has " << _hitPoints << " Hit Points left!" << std::endl;
	}
	else
		std::cout << _name << " can't take damge. He is already 💀 !" << std::endl;
}
