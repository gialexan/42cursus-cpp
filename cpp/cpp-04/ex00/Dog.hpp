#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# include <iostream>
# include <string>

class Dog : public Animal
{
	public:
		void makeSound(void) const;

		Dog(void);							   // Default constructor
		Dog(Dog const &src);                  // Copy constructor
		Dog &operator=(Dog const &rhs);      // Copy assignment operator
		~Dog(void);							// Destructor
};

std::ostream &operator<<( std::ostream &out, Dog const &dog);

#endif /* ************************************************************* DOG_H */