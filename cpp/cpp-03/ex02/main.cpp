/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:53:03 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/18 21:46:31 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main (void)
{
	FragTrap sasuke ("Sasuke");
	FragTrap naruto ("Naruto");

	sasuke.highFivesGuys();
	naruto.highFivesGuys();

	sasuke.attack("Naruto");
	std::cout << "Chidori nagashi! 🌪 " << std::endl;
    
	naruto.beRepaired(5);
	naruto.takeDamage(11);
	naruto.attack("Sasuke");
	std::cout << "Odama rasengan! 🔵" << std::endl;
    
	sasuke.beRepaired(10);
	sasuke.takeDamage(9);
	sasuke.attack("Naruto");
	std::cout << "Katon Goukakyuu! 🔥" << std::endl;
    
	naruto.beRepaired(5);
	naruto.takeDamage(5);
	naruto.attack("Sasuke");
	std::cout << "Rasenshuriken! 🌀" << std::endl;

	sasuke.beRepaired(5);
	sasuke.takeDamage(15);

	std::cout << "Chodama Rasenshuriken! ⚫🌀" << std::endl;
	std::cout << "Indra's Arrow! 🏹🌪" << std::endl;
	
	sasuke.attack("Naruto");
	naruto.attack("Sasuke");

	naruto.takeDamage(100);
	sasuke.takeDamage(100);

	sasuke.beRepaired(1);
	naruto.beRepaired(1);
}