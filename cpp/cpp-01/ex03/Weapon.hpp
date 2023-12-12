/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:49:36 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 12:35:38 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class  Weapon
{
    private:
        std::string _type;    
    public:
        const std::string &getType(void);
        void setType(std::string type);
        
        Weapon(void);
        Weapon(std::string _type);
        ~Weapon(void);
};

#endif
