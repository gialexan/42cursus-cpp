#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal
{
	public:
		void makeSound(void) const;
	
		Cat(void);							   // Default constructor
		Cat(Cat const &src);				  // Copy constructor
		Cat &operator=(Cat const &rhs);      // Copy assignment operator
		~Cat(void);							// Destructor
};

std::ostream &operator<<(std::ostream & out, Cat const & cat);

#endif /* ************************************************************* CAT_H */