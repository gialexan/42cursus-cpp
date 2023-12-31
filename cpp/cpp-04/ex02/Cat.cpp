/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 09:37:03 by gilmar            #+#    #+#             */
/*   Updated: 2023/12/31 06:56:46 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	
	_brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal("Cat")
{
	std::cout << "Cat copy constructor called" << std::endl;

	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;

	delete _brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "*** Meow 🐱! ***"	<< std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */