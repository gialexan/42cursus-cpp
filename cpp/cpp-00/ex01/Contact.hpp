/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:52:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 12:35:11 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"				/* Black */
# define BLUE			"\033[34m"				/* Blue */

# define FIRST_CHAR 0
# define MAX_CHARACTERS 15

class Contact
{
    private:
        std::string _phone;
        std::string _lastName;
        std::string _nickname;
        std::string _firstName;

        bool _isValideField(std::string string);
        void _requestInfo(std::string prompt, std::string &field);
    public:
        std::string getPhone(void);
        std::string getNickname(void);
        std::string getLastName(void);
        std::string getFirstName(void);
        static Contact createContact(void);
        
        Contact(void);
        ~Contact(void);
};

#endif
