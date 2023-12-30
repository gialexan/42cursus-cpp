/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:06:43 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/30 10:35:49 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat")
{
	std::cout << "Wrong Cat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & src)
{
	std::cout << "Wrong Cat copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat default constructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "Wrong Cat assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

std::ostream &operator<<( std::ostream & o, WrongCat const & i )
{
	o << "Value = " << i.getType();
	return o;
}

void WrongCat::makeSound(void) const
{
	std::cout << "*** Wrong Meow 🐱! ***" <<  std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */