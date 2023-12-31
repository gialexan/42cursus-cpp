/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:36:18 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/30 21:34:19 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	_type;
	
	public:
		virtual void makeSound(void) const;
		std::string getType(void) const;
		
		Animal(const std::string type);
		Animal(void);				        	   	   // Default constructor
		Animal(Animal const &obj);					  // Copy constructor
		Animal &operator=(Animal const &rhs);	 	 // Copy assignment operator
		virtual ~Animal(void);						// Destructor
};

#endif /* ********************************************************** ANIMAL_H */