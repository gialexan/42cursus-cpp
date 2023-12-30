/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:03:02 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/30 10:40:53 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	private:
		std::string _type;
	
	public:
		virtual void makeSound(void) const;
		std::string getType(void) const;
		
		WrongAnimal(const std::string type);
		WrongAnimal(void);								       // Default constructor
		WrongAnimal(WrongAnimal const &src);				  // Copy constructor
		WrongAnimal &operator=(WrongAnimal const &rhs);		 // Copy assignment operator
		~WrongAnimal(void);									// Destructor

};

std::ostream &operator<<(std::ostream &o, WrongAnimal const &i);

#endif /* ***************************************************** WRONGANIMAL_H */