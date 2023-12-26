#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(void) : Animal("Cat")
{
}

Cat::Cat(const Cat & src)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &Cat::operator=(Cat const &rhs)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Cat const &i)
{
	//o << "Value = " << i.getValue();
	return o;
}

void Cat::makeSound(void) const
{
	std::cout << "*** Meow 🐱! ***"	<< std::endl;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */