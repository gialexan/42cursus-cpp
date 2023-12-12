/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:51:18 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 12:35:04 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define RESET			"\033[0m"
# define BLACK			"\033[30m"				/* Black */
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define BLUE			"\033[34m"				/* Blue */

# define LIMIT_CONTACT 8

class PhoneBook
{
    private:
        int     _contactNb;
        Contact _book[LIMIT_CONTACT];

        void _printTableRows(void);
        void _displayPhoneBook(void);
        void _printTableHeader(void);
        void _printTableContent(void);
        void _displayContactById(void);
        void _saveContact(Contact contact);
        void _printContact(Contact contact);
        bool _checkEmpyInfo(Contact contact);
        std::string _truncateInfo(std::string string);
    public:
        void addContact(void);
        void searchContact(void);
        
        PhoneBook(void);
        ~PhoneBook(void);
};

#endif
