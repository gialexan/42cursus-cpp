/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:51:32 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/15 22:20:55 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::_contactNb = 0;

PhoneBook::PhoneBook(void) {}

void PhoneBook::phoneBookController(std::string command)
{
    if (command == "ADD")
        createContact();
    else if (command == "LIST")
        listContacts();
    else
		std::cout << "Please enter: CREATE, LIST or EXIT" << std::endl;
}

void PhoneBook::createContact(void)
{
    int id;
    std::string name;
    std::string phone;
                    
	std::cout << "You are adding a contact of index no. " << _contactNb << std::endl;
	id = _contactNb;
    std::cout << "\tname: "; std::getline(std::cin, name);
    std::cout << "\tphone: "; std::getline(std::cin, phone);
    if (name.empty() || phone.empty())
        std::cout << "Please fill in all the information."<< std::endl;
    else if (checkPhoneBookIsFull())
        replaceOldestContact(Contact(id, name, phone));
    else
        saveContact(Contact(id, name, phone), _contactNb);
}

void PhoneBook::listContacts(void)
{
    if (PhoneBook::_contactNb == 0)
        std::cout << "No contact in the phonebook. Use ADD to add a contact first." << std::endl;
    else
    {
		std::cout << "List Contacts:" << std::endl;
        for (int i = 0; i < LIMIT_CONTACT; i++)
        {
            if (!checkEmpyInfo(_book[i]))
                _book[i].toString();
        }
    }
}

void PhoneBook::replaceOldestContact(Contact contact)
{
    int oldestContact = INT_MAX;

    for(int i = 0; i < LIMIT_CONTACT; i++)
    {
        if(_book[i].getId() < oldestContact)
            oldestContact = _book[i].getId();
    }
    saveContact(contact, oldestContact);
}

bool PhoneBook::checkEmpyInfo(Contact contact)
{
    return contact.getName().empty() && contact.getPhone().empty();
}

void PhoneBook::saveContact(Contact contact, int index)
{
    _book[index] = contact;
    _contactNb++;
}

bool PhoneBook::checkPhoneBookIsFull()
{
    return _contactNb >= LIMIT_CONTACT;
}

PhoneBook::~PhoneBook(void) {}
