/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:49:45 by gilmar            #+#    #+#             */
/*   Updated: 2023/12/31 11:09:25 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

int main(void)
{
    Bureaucrat b2 = Bureaucrat("B1", 1);
    Bureaucrat b1 = Bureaucrat("B2", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    
    try
    {
        b1.increment();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        b2.decrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}