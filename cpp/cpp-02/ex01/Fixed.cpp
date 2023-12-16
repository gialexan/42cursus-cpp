/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:51:06 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/16 18:57:27 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

int Fixed::getRawBits() const
{
    return (_value);
}

/*
    ? Copy constructor
    * A new object is created from an existing object (as a copy of the existing objec)
	_num = obj.getRawBits();
*/
Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

/*
    ? Copy Assignment operator (operator overload)
    * An already initialized object is assigned to a new value from another existing object 
*/
Fixed &Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = obj.getRawBits();
    return *this;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl ;
    _value = number << _fractionalBits ;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(number * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return ((float)_value / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

/*
 * The output operator;
*/
std::ostream& operator << (std::ostream& output, const Fixed& src)
{
	output << src.toFloat();
	return (output);
}
