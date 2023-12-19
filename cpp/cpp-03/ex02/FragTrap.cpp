/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:35:21 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/18 21:47:05 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default Constructor called" << std::endl;
    
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = "";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Constructor called" << std::endl;
    
    this->_attackDamage = 100;
    this->_energyPoints = 100;
    this->_hitPoints = 30;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

/*
    ? Copy constructor
    * A new object is created from an existing object (as a copy of the existing objec)
*/
FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

/*
    ? Copy Assignment operator (operator overload)
    * An already initialized object is assigned to a new value from another existing object 
*/
FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;

    _name = obj._name;
    _hitPoints = obj._hitPoints;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;

    return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five Guys!" << std::endl;
}