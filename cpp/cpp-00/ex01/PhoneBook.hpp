/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:51:18 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/20 10:58:41 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include <iostream>
#include "Contact.hpp"

#define RESET			"\033[0m"
#define BLACK			"\033[30m"				/* Black */
#define RED			"\033[31m"				/* Red */
#define GREEN			"\033[32m"				/* Green */
#define BLUE			"\033[34m"				/* Blue */
#define WHITE			"\033[37m"				/* White */
#define BOLDBLACK		"\033[1m\033[30m"		/* Bold Black */
#define BOLDBLUE		"\033[1m\033[34m"		/* Bold Blue */
#define BOLDCYAN		"\033[1m\033[36m"		/* Bold Cyan */
#define BOLDWHITE		"\033[1m\033[37m"		/* Bold White */

#define LIMIT_CONTACT 8

class PhoneBook
{
    private:
        Contact _book[LIMIT_CONTACT];
        int     _contactNb;
        
        void _saveContact(Contact contact);
        void _printContact(Contact contact);
        bool _checkEmpyInfo(Contact contact);
    public:
        void addContact(void);
        void searchContact(void);
        
        PhoneBook(void);
        ~PhoneBook(void);
};

#endif
