/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:36:18 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/31 06:56:11 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string	_type;
	
	public:
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
		
		AAnimal(const std::string type);
		AAnimal(void);				        	   	   // Default constructor
		AAnimal(AAnimal const &obj);				  // Copy constructor
		AAnimal &operator=(AAnimal const &rhs);	 	 // Copy assignment operator
		virtual ~AAnimal(void);						// Destructor
};

#endif /* ********************************************************** ANIMAL_H */