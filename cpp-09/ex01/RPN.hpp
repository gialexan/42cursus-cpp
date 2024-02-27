/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:54:11 by gilmar            #+#    #+#             */
/*   Updated: 2024/02/14 10:35:06 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <list>
# include <sstream>

enum TokenType
{
	NUMBER,
	OPERATOR
};

class RPN
{
	public:
		static int eval(const std::string& expression);

	private:
		RPN(void);
		
		static TokenType _type(char ch);
		static void _processNumber(char ch);
		static void _processOperator(char ch);
		static int _safetyDivide(int a, int b);
		static void _checkExpression(const std::string& expression);

		typedef std::list<int> List;
		static List m_list;
};

#endif /* ************************************************************* RPN_H */