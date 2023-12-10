/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:00 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:53:05 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    // if (argc != 2)
    // {
    //     std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
    //     return (1);
    // }
    Harl harl;  
    harl.complain("DEBUG");
}
