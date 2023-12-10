/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:31:22 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:52:20 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET			"\033[0m"
#define RED			    "\033[31m"				/* Red */
#define GREEN			"\033[32m"				/* Green */

int main(void)
{
    std::string string =  "HI THIS IS BRAIN";

    std::string *stringPTR = &string;
    std::string &stringREF = string;
    
    std::cout << RED << "The memory address:" << std::endl << RESET;
    std::cout << "\tstring: " << GREEN << &string << std::endl << RESET;
    std::cout << "\tstringPTR: " << GREEN << stringPTR << std::endl << RESET;
    std::cout << "\tstringREF: " << GREEN << &stringREF << std::endl << RESET;
    
    std::cout << RED << "The memory content:" << std::endl << RESET;
    std::cout << "\tstring: " << GREEN << string << std::endl << RESET;
    std::cout << "\tstringPTR: " << GREEN << *stringPTR << std::endl << RESET;
    std::cout << "\tstringREF: " << GREEN << stringREF << std::endl << RESET; 
}
