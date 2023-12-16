/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:53:03 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/16 20:31:09 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap sasuke ("Sasuke");
	ClapTrap naruto ("Naruto");
	
	sasuke.attack("Naruto");
	std::cout << "chidori nagashi! 🌪 " << std::endl;
    
	naruto.beRepaired(5);
	naruto.takeDamage(11);
	naruto.attack("Sasuke");
	std::cout << "odama rasengan! 🔵" << std::endl;
    
	sasuke.beRepaired(10);
	sasuke.takeDamage(9);
	sasuke.attack("Naruto");
	std::cout << "Katon Goukakyuu! 🔥" << std::endl;
    
	naruto.beRepaired(5);
	naruto.takeDamage(11);
	naruto.attack("Sasuke");
}