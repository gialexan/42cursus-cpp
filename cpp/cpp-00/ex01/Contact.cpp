/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:52:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/20 10:56:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::getName(void) {return _name;}

std::string Contact::getPhone(void) {return _phone;}

std::string Contact::getNickname(void) {return _nickname;}

Contact Contact::createContact(void)
{
    Contact contact = Contact();

    contact._requestInfo("NAME", contact._name);
    contact._requestInfo("NICKNAME", contact._nickname);
    contact._requestInfo("PHONE", contact._phone);

    return contact;
}

void Contact::_requestInfo(std::string prompt, std::string &contactField)
{
    do
    {
        std::cout << BLUE << "Enter your " << BOLDBLUE << prompt << ": ";
	    std::getline(std::cin, contactField);
        std::cout << RESET;
    }
    while (_isValideField(contactField));
}

bool Contact::_isValideField(std::string contactField)
{
    return isspace(contactField[FIRST_CHAR]) || 
        contactField.length() > MAX_CHARACTERS || 
        contactField.empty();
}
