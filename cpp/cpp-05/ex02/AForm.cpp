/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:31:24 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/14 18:01:29 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(void)
{
	// std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec) : 
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

AForm::AForm(const AForm &src)
{
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm(void)
{
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
    	_isSigned = rhs._isSigned;
  	}
  	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
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

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form note signed";
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!getIsSigned())
	{
		throw FormNotSignedException();
	}
	
	if (bureaucrat.getGrade() > _gradeToExecute)
	{
		throw GradeTooLowException();
	}
	
	executeAction();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName(void) const { return _name; }

int AForm::getGradeToSign(void) const { return _gradeToSign; }

int AForm::getGradeToExecute(void) const { return _gradeToExecute; }

bool AForm::getIsSigned(void) const { return _isSigned; }

/* ************************************************************************** */