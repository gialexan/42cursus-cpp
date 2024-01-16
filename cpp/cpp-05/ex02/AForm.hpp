/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:27:17 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/14 18:01:34 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		int _gradeToSign;
		int _gradeToExecute;

		virtual void executeAction(void) const = 0;

	public:
		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool getIsSigned(void) const;

		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(void);
		AForm(AForm const &src);
		AForm &operator=(AForm const &rhs);
		~AForm(void);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, AForm const &i);

#endif /* ************************************************************ FORM_H */