/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:50:48 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/04 20:07:27 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */

class  HumanA
{
    private:
        std::string _name;
        Weapon &_weapon;
    public:
        void attack(void);
    
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
};

#endif