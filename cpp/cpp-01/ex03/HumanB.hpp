/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:50:40 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:52:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

#define RESET		"\033[0m"
#define RED			"\033[31m"				/* Red */
#define GREEN		"\033[32m"				/* Green */

class  HumanB
{
    private:
        std::string _name;
        Weapon *_weapon;
    public:
        void attack(void);
        void setWeapon(Weapon &weapon);
        
        HumanB(std::string name);
        ~HumanB(void);
};

#endif
