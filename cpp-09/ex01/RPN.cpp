/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:55:52 by gilmar            #+#    #+#             */
/*   Updated: 2024/02/14 10:58:02 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::List RPN::m_list; 

RPN::RPN(void)
{
}

int RPN::eval(const std::string& expression)
{
	_checkExpression(expression);
	std::istringstream iss(expression);

	char ch;
	while(iss >> ch)
	{
		switch (_type(ch))
		{
			case NUMBER:
				_processNumber(ch);
				break;
			case OPERATOR:
				_processOperator(ch);
				break;
		}
	}

	return m_list.back();
}

void RPN::_checkExpression(const std::string& expression)
{
    for (size_t i = 0; i < expression.size() - 1; ++i)
	{
        if (expression[i] == ' ' && expression[i + 1] == ' ')
		{
            throw std::runtime_error("Invalid expression. Error: double space");
        }

        if (std::isdigit(expression[i]) && std::isdigit(expression[i + 1]))
		{
            throw std::runtime_error("Invalid expression. Error: number bigger than 9");
        }
    }
}

void RPN::_processNumber(char ch)
{
	m_list.push_back(ch - '0');
}

void RPN::_processOperator(char ch)
{
	if (m_list.size() < 2)
	{
		throw std::runtime_error("Invalid expression. Error: not enough numbers");
	}

	int term2 = m_list.back();
	m_list.pop_back();

	int term1 = m_list.back();
	m_list.pop_back();
	
	int result = 0;
	switch(ch)
	{
		case '+':
			result = term1 + term2;
			break;
		case '-':
			result = term1 - term2;
			break;
		case '*':
			result = term1 * term2;
			break;
		case '/':
			result = _safetyDivide(term1, term2);
			break;
		default:
        	throw std::runtime_error("invalid operator");
	}

	m_list.push_back(result);
}

int RPN::_safetyDivide(int a, int b)
{
	if (b == 0)
	{
		throw std::runtime_error("Invalid expression. Error: division by zero");
	}

	return a / b;
}

TokenType RPN::_type(char ch)
{
	if (isdigit(ch))
	{
		return NUMBER;
	}
	
	return OPERATOR;
}

/* ************************************************************************** */