/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:52:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 12:07:49 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::getFirstName(void)
{
    return _firstName;
}

std::string Contact::getLastName(void)
{
    return _lastName;
};

std::string Contact::getPhone(void)
{
    return _phone;
}

std::string Contact::getNickname(void)
{
    return _nickname;
}

Contact Contact::createContact(void)
{
    Contact contact = Contact();

    contact._requestInfo("FIRST NAME", contact._firstName);
    contact._requestInfo("LAST NAME", contact._lastName);
    contact._requestInfo("NICKNAME", contact._nickname);
    contact._requestInfo("PHONE", contact._phone);

    return contact;
}

void Contact::_requestInfo(std::string prompt, std::string &field)
{
    do
    {
        std::cout << BLACK << "Enter your " << BLUE << prompt << BLACK << ": " << RESET;
	    std::getline(std::cin, field);
    }
    while (_isValideField(field));
}

bool Contact::_isValideField(std::string string)
{
    return isspace(string[FIRST_CHAR]) || string.empty();
}
