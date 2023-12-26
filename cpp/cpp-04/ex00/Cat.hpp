#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal
{
	public:
		void makeSound(void) const;
	
		Cat(void);
		Cat(Cat const & src);
		Cat &operator=(Cat const & rhs);
		~Cat(void);
};

std::ostream &operator<<(std::ostream & out, Cat const & cat);

#endif /* ************************************************************* CAT_H */