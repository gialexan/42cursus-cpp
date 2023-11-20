/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:02:14 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/20 10:55:52 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main (void)
{
    std::string command;
  
    std::cout << BOLDCYAN << "Welcome to the C++ PhoneBook!" << RESET << std::endl;
    PhoneBook book = PhoneBook();
    while(command != "EXIT")
    {
        std::cout << BLACK << "Enter your command: " << BOLDBLACK;
        std::getline(std::cin, command);
        std::cout << RESET;
        if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
        else if (command == "ADD")
            book.addContact();
        else if (command == "SEARCH")
            book.searchContact();
        else
            std::cout << RED << "Please enter: ADD, SEARCH or EXIT" << RESET << std::endl;
    }
    return (0);
}
