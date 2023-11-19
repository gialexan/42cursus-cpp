/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:52:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/15 22:18:26 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(int id, std::string name, std::string phone)
{
    _id = id;
    _name = name;
    _phone = phone;
}

int Contact::getId(void)
{
    return _id;
}

std::string Contact::getName(void)
{
    return _name;
}

std::string Contact::getPhone(void)
{
    return _phone;
}

void Contact::toString(void)
{
    std::cout << "\tname: " << _name << std::endl;
    std::cout << "\tphone: " << _phone << std::endl;
}

Contact::~Contact(void) {}
