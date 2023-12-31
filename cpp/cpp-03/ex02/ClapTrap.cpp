/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:52:27 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/31 08:44:14 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) 
{
    std::cout << "ClassTrap Destructor called" << std::endl;
}

/*
    ? Copy Assignment operator (operator overload)
    * An already initialized object is assigned to a new value from another existing object 
*/
ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClassTrap Copy assignment operator called" << std::endl;
    
    _name = obj._name;
    _hitPoints = obj._hitPoints;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;

    return *this;
}

/*
    ? Copy constructor
    * A new object is created from an existing object (as a copy of the existing objec)
*/
ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "ClassTrap Copy constructor called" << std::endl;
    *this = obj;
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
