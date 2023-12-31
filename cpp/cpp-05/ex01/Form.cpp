/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:31:24 by gilmar            #+#    #+#             */
/*   Updated: 2023/12/31 15:36:37 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(void)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeSign, int gradeExec) : 
	_name(name), _isSigned(false), _gradeToSign(gradeSign), _gradeToExecute(gradeExec)
{
	if (_gradeToSign < HIGHEST_GRADE || gradeExec < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	else if (_gradeToExecute > LOWEST_GRADE || _gradeToSign > LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
}

Form::Form(const Form &src)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
    	_isSigned = rhs._isSigned;
  	}
  	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form " << i.getName() << " requires grade " << i.getGradeToSign()
    	<< " to sign and grade " << i.getGradeToExecute() << " to execute."
    	<< std::endl;
	
	if (i.getIsSigned())
	{
		o << "Form is signed." << std::endl;
	}
	else
	{
		o << "Form is not signed." << std::endl;
	}
	
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	else
	{
		_isSigned = true;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const { return _name; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

bool Form::getIsSigned() const { return _isSigned; }

/* ************************************************************************** */