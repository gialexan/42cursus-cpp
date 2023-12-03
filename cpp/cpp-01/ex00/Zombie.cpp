/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:13:42 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/29 19:45:42 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string string) {_name = string;}

Zombie::~Zombie(void)
{
  std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
