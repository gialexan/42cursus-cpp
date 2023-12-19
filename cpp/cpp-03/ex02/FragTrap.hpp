/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:35:12 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/18 21:44:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap:public ClapTrap
{
    public:
        FragTrap(std::string name);
        void highFivesGuys(void);
        FragTrap(const FragTrap &obj);                // Copy constructor
        FragTrap(void);                              // Default constructor
        FragTrap &operator=(FragTrap const &obj);   // Copy assignment operator
        ~FragTrap();                               // Destructor
};

#endif