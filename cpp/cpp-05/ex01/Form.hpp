/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:27:17 by gilmar            #+#    #+#             */
/*   Updated: 2023/12/31 15:34:27 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		int _gradeToSign;
		int _gradeToExecute;

	public:
		void beSigned(Bureaucrat &bureaucrat);

		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool getIsSigned(void) const;

		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(void);
		Form(Form const &src);
		Form &operator=(Form const &rhs);
		~Form(void);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */