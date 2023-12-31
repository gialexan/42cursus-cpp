/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:49:45 by gilmar            #+#    #+#             */
/*   Updated: 2023/12/31 15:43:12 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <exception>

int main(void)
{
    Bureaucrat b2 = Bureaucrat("B2", 1);
    Bureaucrat b1 = Bureaucrat("B1", 150);

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

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << "---------------------" << std::endl;
    
    Form f1 = Form("f1", 1, 1);
    Form f2 = Form("f2", 150, 150);

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    // b2 can't sign the form because he's not the big boss
    try
    {
        b1.signForm(f1);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // b2 can sign the form because he has the necessary grade level
    try
    {
        b2.signForm(f1);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
        
    return (0);
}