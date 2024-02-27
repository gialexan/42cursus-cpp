/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:26:55 by gilmar            #+#    #+#             */
/*   Updated: 2024/02/14 10:12:57 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>

const char CSV_DELIMITER = ',';
const char CSV_FILE[] = "data.csv";
const char DELIMITER[] = " | ";

typedef float BTC;
typedef float Price;
typedef std::string Date;

class BitcoinExchange
{
	public:
		static void loadDatabase(void);
		static void openInputFile(const std::string &filename);
		void openfileteste(const std::string & filename);
		static void processBitcoinExchange(void);

	private:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		static void _processLine(const std::string &line, size_t pos);
		static Date _parseDate(const std::string &date);
		static Price _parseValue(const std::string &price);
		static Price _getPrice(const Date &date);
		static void _printError(const std::string &errorMsg);

		typedef std::map<Date, Price> ExchangeRateDatabase;
		static ExchangeRateDatabase m_database;

		typedef std::ifstream File;
		static File m_file;
};

#endif /* ************************************************  BITCOINEXCHANGE_H */