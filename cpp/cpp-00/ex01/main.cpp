/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:02:14 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/12 21:43:44 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include "PhoneBook.hpp"

int main (void)
{
    std::string command;
    PhoneBook controller;

    
    controller = PhoneBook();
    std::cout << "Welcome to the C++ phoneBook!" << std::endl;
    while(command != "EXIT")
    {
        std::cout << "Enter your command: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
        controller.phoneBookController(command);
    }

    return (0);
}
