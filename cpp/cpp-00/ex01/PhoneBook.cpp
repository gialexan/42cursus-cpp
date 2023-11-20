/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:51:32 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/20 16:36:48 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {_contactNb = -1;}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(void)
{
    std::cout << BLUE << "You are adding a new contact." << std::endl << RESET;
    Contact contact = Contact::createContact();
    _saveContact(contact);
}

void PhoneBook::searchContact(void)
{
    if (_contactNb == -1)
        std::cout << RED << "No contact in the phonebook. Use ADD to add a contact first." << std::endl << RESET;
    else
    {
        _displayPhoneBook();
        _displayContactById();
    }
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

void PhoneBook::_displayContactById(void)
{
    std::string aux;
    int         index;
    
    std::cout << BLACK << "Input the desired index: " << RESET;
    std::getline(std::cin, aux);
    if (aux.empty() || isspace(aux[FIRST_CHAR]))
        std::cout << RED << "Please SEARCH again and enter a valid number. " << std::endl << RESET;
    else
    {
        index = std::atoi(aux.c_str());
        if (index > LIMIT_CONTACT || index < 0)
            std::cout << RED << "Invalid index, it must be between 0 and 7." << std::endl;
        else
        {
            if (_checkEmpyInfo(_book[index]) == false)
                _printContact(_book[index]);
            else
                std::cout << RED << "No contact saved in this index." << std::endl;
        }
    }
}

void PhoneBook::_displayPhoneBook(void)
{
    std::cout << BLUE << "Saved Contacts:" << std::endl;
    std::cout << BLACK;
    _printTableHeader();
    _printTableRows();
    _printTableContent();
    std::cout << RESET;
}

void PhoneBook::_printTableHeader(void)
{
    std::cout << std::left << "|" << std::setw(15) << "INDEX" << "|"
              << std::setw(15) << "FIRST NAME" << "|"
              << std::setw(15) << "LAST NAME" << "|" 
              << std::setw(15) << "NICKNAME" << "|" 
              << std::endl;
}

void PhoneBook::_printTableRows(void)
{
    std::cout << std::setfill('-') << "|" 
              << std::setw(15) << "" << "|"
              << std::setw(15) << "" << "|"
              << std::setw(15) << "" << "|"
              << std::setw(15) << "" << "|" << std::endl;
}

void PhoneBook::_printTableContent(void)
{
    for (int i = 0; i < LIMIT_CONTACT; i++)
    {
        if (_checkEmpyInfo(_book[i]) == false)
        {
            std::cout << std::left << std::setfill(' ') << "|" 
                    << std::setw(15) << i << "|"
                    << std::left << std::setw(15)
                    << _truncateInfo(_book[i].getFirstName()) << "|"
                    << std::left << std::setw(15)
                    << _truncateInfo(_book[i].getLastName()) << "|"
                    << std::left << std::setw(15)
                    << _truncateInfo(_book[i].getNickname()) << "|"
                    << std::endl;
        }
    }
}

void PhoneBook::_printContact(Contact contact)
{
    std::cout << BLUE << "Contact Detail:" << std::endl << RESET;
    std::cout << BLACK << "FIRST NAME : [" << RESET << contact.getFirstName() << BLACK << "]" << std::endl;
    std::cout << BLACK << "LAST NAME  : [" << RESET << contact.getLastName() << BLACK << "]" << std::endl;
	std::cout << BLACK << "NICKNAME   : [" << RESET << contact.getNickname()  << BLACK << "]" << std::endl;
	std::cout << BLACK << "PHONE      : [" << RESET << contact.getPhone() << BLACK << "]" << std::endl;
}

std::string PhoneBook::_truncateInfo(std::string string)
{
    if (string.length() > 10)
        return string.substr(0, 9) + ".";
    else 
        return string;
}

bool PhoneBook::_checkEmpyInfo(Contact contact)
{
    return contact.getFirstName().empty() && 
        contact.getLastName().empty() &&
        contact.getPhone().empty() && 
        contact.getNickname().empty();
}
