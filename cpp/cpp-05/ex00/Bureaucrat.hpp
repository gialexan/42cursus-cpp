/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:51:03 by gilmar            #+#    #+#             */
/*   Updated: 2023/12/31 10:02:04 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		std::string getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);

		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		~Bureaucrat(void);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, Bureaucrat const &i);

#endif /* ****************************************************** BUREAUCRAT_H */