/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:52:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/20 10:58:12 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>


#define FIRST_CHAR 0
#define MAX_CHARACTERS 15

#define RESET			"\033[0m"
#define BLUE			"\033[34m"				/* Blue */
#define BOLDBLUE		"\033[1m\033[34m"		/* Bold Blue */

class Contact
{
    private:
        std::string _name;
        std::string _phone;
        std::string _nickname;

        bool _isValideField(std::string contactField);
        void _requestInfo(std::string prompt, std::string &contactField);
    public:
        std::string getName(void);
        std::string getPhone(void);
        std::string getNickname(void);
        static Contact createContact(void);
        
        Contact(void);
        ~Contact(void);
};

#endif
