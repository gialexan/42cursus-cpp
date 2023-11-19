/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:52:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/12 21:04:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        int _id;
        std::string _name;
        std::string _phone;
    public:
        int getId(void);
        void toString(void);
        std::string getName(void);
        std::string getPhone(void);
              
        Contact(int id, std::string name, std::string phone);
        Contact(void);
        ~Contact(void);
};

#endif