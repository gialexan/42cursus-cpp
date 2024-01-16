/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:00:25 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 17:35:41 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::pseudoLiterals[maxPseudoLiterals] = {
	"-inff", "+inff", "inff", "nan", "nanf", "-inf", "+inf", "inf"
};

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, ConversionPack const &rhs)
{
	printCharConversion(o, rhs);
	
	o << std::endl;

	printIntConversion(o, rhs);

	o << std::endl;
	o << std::fixed << std::setprecision(1);

	printFloatConversion(o, rhs);
	
	o << std::endl;
	
	printDoubleConversion(o, rhs);

	return o;
}

/*
** -------------------------------- Print --------------------------------
*/

void printCharConversion(std::ostream &o, ConversionPack const &rhs)
{
	o << "Char: ";

	if (!rhs.isValidChar)
	{
		o << "Impossible";
	}
	else if (std::isprint(rhs.charValue))
	{
		o << "'" << rhs.charValue << "'";
	}
	else
	{
		o << "Non-displayable";
	}
}

void printIntConversion(std::ostream &o, ConversionPack const &rhs)
{
	o << "Int: ";

	if (rhs.isValidInt)
	{
		o << rhs.intValue;
	}
	else
	{
		o << "Impossible";
	}
}

void printFloatConversion(std::ostream &o, ConversionPack const &rhs)
{
	o << "Float: ";

	if (rhs.isValidFloat)
	{
		o << rhs.floatValue << "f";
	}
	else
	{
		o << "Impossible";
	}
}

void printDoubleConversion(std::ostream &o, ConversionPack const &rhs)
{
	o << "Double: ";

	if (rhs.isValidDouble)
	{
		o << rhs.doubleValue;
	}
	else
	{
		o << "Impossible";
	}
}

/*
** --------------------------------- VALIDATIONS ----------------------------------
*/

bool ScalarConverter::isSign(char c)
{
	if (c == '-' || c == '+')
		return true;
	return false;
}

ScalarType ScalarConverter::isChar(const std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return CHAR;
	return UNKNOWN;
}

ScalarType ScalarConverter::isNumber(const std::string &literal)
{
	bool hasF = false;
	bool hasDot = false;
	
	int idx = 0;
	if (isSign(literal[idx]))
	{
		++idx;
	}

	int length = literal.length();
	while (idx < length)
	{
		if (literal[idx] == '.')
		{
			if (hasDot)
				return UNKNOWN;
			hasDot = true;
		}
		else if (literal[idx] == 'f' || literal[idx] == 'F')
		{
			if (hasF)
				return UNKNOWN;
			hasF = true;
		}
		else if (!std::isdigit(literal[idx]))
			return UNKNOWN;
		idx++;
	}
	
	return hasF ? FLOAT : (hasDot ? DOUBLE : INT);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

ConversionPack ScalarConverter::newPack()
{
	ConversionPack item;

	item.isValidChar = true;
	item.isValidInt = true;
	item.isValidFloat = true;
	item.isValidDouble = true;

	item.charValue = 0;
	item.intValue = 0;
	item.floatValue = 0;
	item.doubleValue = 0;

	return item;
}

ScalarType ScalarConverter::checkPseudoLiterals(const std::string &literal)
{
	int idx = 0;

	while (idx < maxPseudoLiterals)
	{
		if (literal == pseudoLiterals[idx])
			return PSEUDO;
		idx++;
	}
	
	return UNKNOWN;
}

ScalarType ScalarConverter::parseScalarType(const std::string &literal)
{	
	ScalarType type = isChar(literal);

	if (type != UNKNOWN)
	{
		return type;
	}
	
	type = isNumber(literal);
	if (type != UNKNOWN)
	{
		return type;
	}

	return checkPseudoLiterals(literal);
}

void ScalarConverter::convert(const std::string &literal)
{
	ScalarType type = parseScalarType(literal);

	switch (type)
	{
		case CHAR:
			charConversions(literal);
			break;
		case INT:
			intConversions(literal);
			break;
		case FLOAT:
			floatConvertions(literal);
			break;
		case DOUBLE:
			doubleConvertions(literal);
			break;
		case PSEUDO:
			pseudoLiteralsConvertions(literal);
			break;
		default:
			impossibleConversion(literal);	
			break;
	}
}

/*
** --------------------------------- CONVERTIONS ---------------------------------
*/

double ScalarConverter::extractPseudoLiterals(const std::string &literal)
{
	double value = 0;

	if (literal.find("nan") != std::string::npos)
	{
		value = std::numeric_limits<double>::quiet_NaN();
	}
	
	if (literal.find("inf") != std::string::npos)
	{
		value = std::numeric_limits<double>::infinity();
		if (literal[0] == '-')
			value = -value;
	}
	
	return value;
}

void ScalarConverter::pseudoLiteralsConvertions(const std::string &literal)
{
	ConversionPack pack = newPack();
	
	double value = extractPseudoLiterals(literal);
	long longValue = static_cast<long>(value);

	pack.charValue = static_cast<char>(value);
	pack.isValidChar = (pack.charValue == longValue);
	
	pack.intValue = static_cast<int>(value);
	pack.isValidInt = (pack.intValue == longValue);
	
	pack.floatValue = static_cast<float>(value);
	pack.doubleValue = value;

	std::cout << pack << std::endl;
}

void ScalarConverter::impossibleConversion(const std::string &)
{
	ConversionPack pack = newPack();

	pack.isValidChar = false;
	
	pack.isValidInt = false;

	pack.isValidFloat = false;

	pack.isValidDouble = false;

	std::cout << pack << std::endl;
}

void ScalarConverter::charConversions(const std::string &literal)
{
	ConversionPack pack = newPack();

	char value = literal[0];

	pack.charValue = value;

	pack.intValue = static_cast<int>(value);

	pack.floatValue = static_cast<float>(value);
	
	pack.doubleValue = static_cast<double>(value);

	std::cout << pack << std::endl;
}

void ScalarConverter::intConversions(const std::string &literal)
{
	ConversionPack pack = newPack();

	int value = std::atoi(literal.c_str());
	long longValue = std::atol(literal.c_str());

	pack.charValue = static_cast<char>(value);
	pack.isValidChar = (pack.charValue == longValue);
	
	pack.intValue = value;
	pack.isValidInt = (pack.intValue == longValue);
	
	pack.floatValue = static_cast<float>(std::strtof(literal.c_str(), 0));
	
	pack.doubleValue = static_cast<double>(std::strtod(literal.c_str(), 0));
	
	std::cout << pack << std::endl;
}

void ScalarConverter::floatConvertions(const std::string &literal)
{
	ConversionPack pack = newPack();

	float value = std::strtof(literal.c_str(), 0);
	long longValue = std::atol(literal.c_str());

	pack.charValue = static_cast<char>(value);
	pack.isValidChar = (pack.charValue == longValue);

	pack.intValue = static_cast<int>(value);
	pack.isValidInt = (pack.intValue == longValue);

	pack.floatValue = value;
	pack.doubleValue = value;

	std::cout << pack << std::endl;
}

void ScalarConverter::doubleConvertions(const std::string &literal)
{
	ConversionPack pack = newPack();

	double value = std::atof(literal.c_str());
	long longValue = std::atol(literal.c_str());

	pack.charValue = static_cast<char>(value);
	pack.isValidChar = (pack.charValue == longValue);

	pack.intValue = static_cast<int>(value);
	pack.isValidInt = (pack.intValue == longValue);

	pack.floatValue = static_cast<float>(value);
	pack.isValidFloat = (pack.floatValue == value);

	pack.doubleValue = value;

	std::cout << pack << std::endl;
}

/* ************************************************************************** */