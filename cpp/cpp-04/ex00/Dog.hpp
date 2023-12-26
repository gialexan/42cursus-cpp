#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# include <iostream>
# include <string>

class Dog : public Animal
{
	public:
		void makeSound(void) const;

		Dog(void);
		Dog(Dog const &src);
		Dog &operator=(Dog const & rhs);
		~Dog(void);
};

std::ostream &operator<<( std::ostream &out, Dog const &dog);

#endif /* ************************************************************* DOG_H */