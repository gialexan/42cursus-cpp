/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:34:02 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/17 19:28:04 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        void guardGate(void);
        ScavTrap(const ScavTrap &obj);
        ScavTrap &operator=(const ScavTrap &obj);
        ScavTrap(std::string name);
        ScavTrap(void);
        ~ScavTrap(void);
};

#endif