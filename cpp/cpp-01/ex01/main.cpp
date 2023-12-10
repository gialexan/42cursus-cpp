/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:13:53 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:52:08 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int n = 10;

    std::cout << RED << "Creating a zombie horde" << RESET << std::endl;
    Zombie *horde = zombieHorde(n, "zombie");
    for (int i = 0; i < n; i++)
        horde[i].announce();
    std::cout << RED << "Killing the horde of zombies" << RESET << std::endl;
    delete[] horde;
}
