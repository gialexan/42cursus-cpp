#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(void) : _type("Animal")
{
}

Animal::Animal(const Animal &src)
{
}

Animal::Animal(const std::string type) : _type(type) 
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator=(Animal const & rhs)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Animal const &i)
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound(void) const
{
	std::cout << "*** Animal sound ***"	<< std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType(void) const
{
	return _type;
}


/* ************************************************************************** */