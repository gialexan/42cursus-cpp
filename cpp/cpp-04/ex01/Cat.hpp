#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <iostream>
# include <string>

class Cat : public Animal
{
	private:
		Brain *_brain;
	
	public:
		void makeSound(void) const;
	
		Cat(void);							   // Default constructor
		Cat(Cat const &src);				  // Copy constructor
		Cat &operator=(Cat const &rhs);      // Copy assignment operator
		~Cat(void);							// Destructor
};

#endif /* ************************************************************* CAT_H */