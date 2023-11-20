/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:02:14 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/20 15:53:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main (void)
{
    std::string command;
  
    std::cout << GREEN << "Welcome to the C++ PhoneBook!" << std::endl << RESET;
    PhoneBook book = PhoneBook();
    while(command != "EXIT")
    {
        std::cout << BLACK << "Enter your command: " << RESET;
        std::getline(std::cin, command);
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
            std::cout << RED << "Please enter: ADD, SEARCH or EXIT" << std::endl << RESET;
    }
    return (0);
}
