#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <iostream>
# include <string>

class Dog : public Animal
{
	private:
		Brain *_brain;
	
	public:
		void makeSound(void) const;

		Dog(void);							   // Default constructor
		Dog(Dog const &src);                  // Copy constructor
		Dog &operator=(Dog const &rhs);      // Copy assignment operator
		~Dog(void);							// Destructor
};

#endif /* ************************************************************* DOG_H */