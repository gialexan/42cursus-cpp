/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:02:41 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 12:35:51 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define TOTAL_LEVEL 4

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define YELLOW			"\033[33m"				/* Yellow */

class Harl
{
    private:
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
        
    public:
        void complain(std::string level);

        Harl(void);
        ~Harl(void);
};

#endif
