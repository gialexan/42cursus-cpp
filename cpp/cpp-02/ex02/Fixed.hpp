/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:47:07 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/16 17:34:32 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
        float toFloat(void) const;
        int toInt(void) const;

        /*
        * The comparison operators:
        */
        bool operator>(const Fixed &obj) const;
        bool operator<(const Fixed &obj) const;
        bool operator>=(const Fixed &obj) const;
        bool operator<=(const Fixed &obj) const;
        bool operator==(const Fixed &obj) const;
        bool operator!=(const Fixed &obj) const;

        /*
        * The 4 arithmetic operators:
        */
        Fixed operator+(const Fixed &obj) const;
        Fixed operator-(const Fixed &obj) const;
        Fixed operator*(const Fixed &obj) const;
        Fixed operator/(const Fixed &obj) const;

        
        /*
        * The increment/decrement
        */
        Fixed &operator++(void);    // Pré-incremento
        Fixed operator++(int);      // Pós-incremento
        Fixed &operator--(void);    // Pré-decremento
        Fixed operator--(int);      // Pós-decremento

        // Funções estáticas min e max
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        Fixed(int const number);
        Fixed(float const number);
        Fixed(void);                           // Default constructor
        Fixed(const Fixed &obj);              // Copy constructor
        Fixed &operator=(const Fixed& obj);  // Copy assignment operator
        ~Fixed(void);                       // Destructor
};

std::ostream & operator << (std::ostream &COUT, const Fixed &fixed);

#endif