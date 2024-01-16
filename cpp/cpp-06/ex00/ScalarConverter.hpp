/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:35:18 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 17:07:31 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>

enum ScalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	UNKNOWN
};

struct ConversionPack
{
	bool isValidChar;
	bool isValidInt;
	bool isValidFloat;
	bool isValidDouble;

	char charValue;
	int intValue;
	float floatValue;
	double doubleValue;
};

class ScalarConverter
{
	public:
		static void convert(const std::string &literal);

	private:
		static ConversionPack newPack();

		static const int maxPseudoLiterals = 8;
		static std::string pseudoLiterals[maxPseudoLiterals];

		static bool isSign(char c);
		static ScalarType isChar(const std::string &literal);
		static ScalarType isNumber(const std::string &literal);
		static ScalarType parseScalarType(const std::string &literal);

		static void charConversions(const std::string &literal);
		static void intConversions(const std::string &literal);
		static void floatConvertions(const std::string &literal);
		static void doubleConvertions(const std::string &literal);
		static void impossibleConversion(const std::string &literal);
		static void pseudoLiteralsConvertions(const std::string &literal);
		static double extractPseudoLiterals(const std::string &literal);

		static ScalarType checkPseudoLiterals(const std::string &literal);
		
		ScalarConverter();
};

std::ostream &operator<<(std::ostream & o, const  ConversionPack &i);
void printCharConversion(std::ostream &o, const ConversionPack &rhs);
void printIntConversion(std::ostream &o, const ConversionPack &rhs);
void printFloatConversion(std::ostream &o, const ConversionPack &rhs);
void printDoubleConversion(std::ostream &o, const ConversionPack &rhs);

#endif /* ************************************************* SCALARCONVERTER_H */