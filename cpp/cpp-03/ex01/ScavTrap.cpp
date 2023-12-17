/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:48:26 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/17 19:51:56 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default Constructor called" << std::endl;
    
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = "";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor called" << std::endl;
    
    this->_attackDamage = 100;
    this->_energyPoints = 50;
    this->_hitPoints = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

/*
    ? Copy constructor
    * A new object is created from an existing object (as a copy of the existing objec)
*/
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

/*
    ? Copy Assignment operator (operator overload)
    * An already initialized object is assigned to a new value from another existing object 
*/
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;

    _name = obj._name;
    _hitPoints = obj._hitPoints;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;

    return *this;
}

void ScavTrap::guardGate(void)
{
    std::cout << _name << " is now in Gate keeper mode" << std::endl;
}