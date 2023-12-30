/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:02:54 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/30 10:41:28 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal
{
	public:
		void makeSound(void) const;

		WrongCat(void);								   // Default constructor
		WrongCat(WrongCat const &src);				  // Copy constructor
		WrongCat &operator=(WrongCat const &rhs);    // Copy assignment operator
		~WrongCat(void);							// Destructor

};

std::ostream &operator<<(std::ostream &o, WrongCat const &i);

#endif /* ******************************************************** WRONGCAT_H */