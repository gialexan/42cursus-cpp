/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:38:17 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/29 19:54:37 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */

class Zombie {
    private:
        std::string _name;
    public:
        ~Zombie(void);
        void announce(void);
        Zombie(std::string name);
        void randomChump(std::string name);
        Zombie* newZombie(std::string name);
};

#endif