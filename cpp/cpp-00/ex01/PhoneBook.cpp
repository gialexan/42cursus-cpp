/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:51:32 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/20 10:49:34 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {_contactNb = -1;}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(void)
{
    std::cout << GREEN << "You are adding a new contact." << RESET << std::endl;
    Contact contact = Contact::createContact();
    _saveContact(contact);
}

void PhoneBook::searchContact(void)
{
    int         i;
    std::string index;

    i = 0;
    if (_contactNb == -1)
    {
        std::cout << RED << "No contact in the phonebook. Use ADD to add a contact first." << RESET << std::endl;
        return ;
    }
    do
    {
       std::cout << WHITE "Input the desired index: " << BOLDWHITE;
       std::getline(std::cin, index); 
       std::cout << RESET;
    }
    while (index.empty() || isspace(index[FIRST_CHAR]));
    i = std::atoi(index.c_str());
    if (i >= 0 && i <= LIMIT_CONTACT && _checkEmpyInfo(_book[i]) == false)
    {
        std::cout << GREEN << "CONTACT DETAIL" << RESET << std::endl;
        _printContact(_book[i]);
    }
    else
        std::cout << RED << "Please SEARCH again and enter a valid index number. " << RESET << std::endl;
}

void PhoneBook::_saveContact(Contact contact)
{
    _contactNb++;
    if (_contactNb < LIMIT_CONTACT)
        _book[_contactNb] = contact;
    else
    {
        for (int i = 0; i < LIMIT_CONTACT - 1; ++i)
            _book[i] = _book[i + 1];
        _book[LIMIT_CONTACT - 1] = contact;
    }
}

void PhoneBook::_printContact(Contact contact)
{
    std::cout << BLUE << "NAME      : " << BOLDBLUE << "[" <<  contact.getName() <<"]" << RESET << std::endl;
	std::cout << BLUE << "NICKNAME  : " << BOLDBLUE << "[" << contact.getNickname()  <<"]" << RESET << std::endl;
	std::cout << BLUE << "PHONE     : " << BOLDBLUE << "[" << contact.getPhone() <<"]" << RESET << std::endl;
}

bool PhoneBook::_checkEmpyInfo(Contact contact)
{
    return contact.getName().empty() && 
        contact.getPhone().empty() && 
        contact.getNickname().empty();
}
