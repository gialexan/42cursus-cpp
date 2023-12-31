/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:34:02 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/18 21:42:27 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        void guardGate(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &obj);                // Copy constructor
        ScavTrap &operator=(const ScavTrap &obj);    // Copy assignment operator
        ScavTrap(void);                             // Default constructor
        ~ScavTrap(void);                           // Destructor
};

#endif