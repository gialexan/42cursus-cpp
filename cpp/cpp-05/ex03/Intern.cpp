/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:24:07 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/14 19:19:21 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"




/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern(void)
{
}

Intern::Intern(const Intern &)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern(void)
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern::FormNotFound::FormNotFound()
    : std::invalid_argument("form not found")
{
}

Intern &Intern::operator=(Intern const &)
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Intern const &)
{
	//o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::createShrubberyForm(const std::string &target)
{
	(void)target;
	return new ShrubberyCreationForm();
}

const Intern::FormCreatorEntry Intern::formCreators[knowForms] = {
	{ "ShrubberyCreationForm", Intern::createShrubberyForm }
};

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{

	AForm *form = NULL;
	
	for (int i = 0; i < knowForms; i++)
	{
		if (formCreators[i].name == name)
		{
			form = formCreators[i].createForm(target);
			break;
		}
	}

	if (!form)
		FormNotFound();

	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */