/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:13:42 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/03 09:48:11 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string string) {_name = string;}

Zombie::~Zombie(void)
{
  std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
