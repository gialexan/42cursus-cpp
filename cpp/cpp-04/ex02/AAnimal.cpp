/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:36:31 by gilmar            #+#    #+#             */
/*   Updated: 2023/12/31 06:55:31 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::AAnimal(const std::string type) : _type(type) 
{
	std::cout << "Animal constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AAnimal::makeSound(void) const
{
	std::cout << "*** Animal sound ***"	<< std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType(void) const
{
	return _type;
}

/* ************************************************************************** */