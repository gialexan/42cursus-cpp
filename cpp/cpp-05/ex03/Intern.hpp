/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:24:12 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/14 19:20:13 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		AForm* makeForm(const std::string &form, const std::string &target);
		Intern &operator=(Intern const &rhs);
	
	private:

		struct FormCreatorEntry
		{
			std::string name;
			AForm* (*createForm)(const std::string &target);
		};

		static const int knowForms = 1;
		static const FormCreatorEntry formCreators[knowForms];
		static AForm *createShrubberyForm(const std::string &target);
		
		class FormNotFound : public std::invalid_argument
		{
			public:
				FormNotFound();
		};
};

std::ostream &operator<<(std::ostream & o, Intern const &i);

#endif /* ********************************************************** INTERN_H */