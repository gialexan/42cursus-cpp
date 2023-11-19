/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:51:18 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/15 22:06:56 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <climits>
#include "Contact.hpp"

#define LIMIT_CONTACT 8

class PhoneBook
{
    private:
        Contact _book[LIMIT_CONTACT];
        static int _contactNb;
        
        void listContacts(void);
        void createContact(void);
        bool checkPhoneBookIsFull(void);
        bool checkEmpyInfo(Contact Contact);
        void replaceOldestContact(Contact contact);
        void saveContact(Contact contact, int index);
    public:
        void phoneBookController(std::string command);
        
        PhoneBook(void);
        ~PhoneBook(void);
};

#endif