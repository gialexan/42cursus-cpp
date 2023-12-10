/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:13:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:51:54 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << RED << "Creating a zombie on the heap" << std::endl << RESET;
    Zombie *heap = newZombie("Zombie Heap");
    heap->announce();
    delete heap;
    
    std::cout << RED << "------------------------------------" << std::endl << RESET;
    std::cout << GREEN << "------------------------------------" << std::endl << RESET;

    std::cout << GREEN << "Creating a zombie on the stack" << std::endl << RESET;
    randomChump("Zombie Stack");
}
