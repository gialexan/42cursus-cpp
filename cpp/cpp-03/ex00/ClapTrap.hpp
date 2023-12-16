/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:52:15 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/16 20:04:54 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>


class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;              // represent the health of the ClapTrap
        int _energyPoints;
        int _attackDamage;
        
    public:
        std::string getName(void) const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
  
        ClapTrap(std::string name);                    // Default constructor
        ClapTrap(const ClapTrap &obj);                // Copy constructor
        ClapTrap &operator=(const ClapTrap &obj);    // Copy assignment operator
        ~ClapTrap(void);                            // Destructor
};

#endif