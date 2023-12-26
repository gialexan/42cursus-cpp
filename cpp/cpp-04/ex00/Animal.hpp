/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:36:18 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/25 18:32:19 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	private:
		std::string	_type;
	
	public:
		virtual void makeSound(void) const;
		std::string getType(void) const;
		
		Animal(const std::string type);
		Animal(void);							   	   // Default constructor
		Animal(Animal const & obj);					  // Copy constructor
		Animal &operator=(Animal const & rhs);	 	 // Copy assignment operator
		~Animal(void);								// Destructor
};

std::ostream &operator<<(std::ostream &out, Animal const &animal);

#endif /* ********************************************************** ANIMAL_H */