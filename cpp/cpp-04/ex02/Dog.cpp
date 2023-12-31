/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:34:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/31 06:57:45 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;

	_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal("Dog")
{
	std::cout << "Dog copy constructor called" << std::endl;
	
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog(void)
{
	std::cout << "Dog destructor constructor called" << std::endl;

	delete _brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		_type = rhs._type;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "*** Woof 🐶! ***"	<< std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */