/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:50:58 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/14 17:59:29 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(void)
{
	//std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	//std::cout << "Bureaucrat custom constructor called" << std::endl;
	
	if (grade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	
	if (grade > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}

	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
	
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs.getGrade();
	}
	
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Bureaucrat::increment(void)
{
	if (_grade + 1 > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	
	_grade++;
}

void Bureaucrat::decrement(void)
{
	if (_grade -1 < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}

	_grade--;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	} 
	catch (std::exception& e)
	{
		std::cerr << this->_name << " cannot sign " << form.getName() << " because "
					<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " cannot execute " << form.getName() << " because "
					<< e.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

/* ************************************************************************** */