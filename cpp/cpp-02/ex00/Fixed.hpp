/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:47:07 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 19:58:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */
# define WHITE			"\033[37m"				/* White */

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits;
        
    public:
        int getRawBits(void) const;
        void setRawBits(int const raw);
    
        Fixed(void);                           // Default constructor
        Fixed(const Fixed &obj);              // Copy constructor
        Fixed &operator=(const Fixed& obj);  // Copy assignment operator
        ~Fixed(void);                       // Destructor
};

#endif