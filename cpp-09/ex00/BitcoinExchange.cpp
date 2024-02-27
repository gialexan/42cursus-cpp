/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:32:13 by gilmar            #+#    #+#             */
/*   Updated: 2024/02/13 16:12:45 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::ExchangeRateDatabase BitcoinExchange::m_database;
BitcoinExchange::File BitcoinExchange::m_file;

void BitcoinExchange::openInputFile(const std::string &filename)
{
	m_file.open(filename);
	if (!m_file)
	{
		throw std::runtime_error("Could not open file");
	}

	if (m_file.peek() == std::ifstream::traits_type::eof())
	{
		m_file.close();
		throw std::runtime_error("File is empty");
	}
}

void BitcoinExchange::loadDatabase(void)
{
	std::string line;
	std::ifstream file(CSV_FILE);
	if (!file)
	{
		throw std::runtime_error("Could not open file");
	}

	Date date;
	date.resize(11);
	Price price;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::sscanf(line.c_str(), "%10s, %f", &date[0], &price);
		m_database[date] = price;
	}
	
	file.close();
}

void BitcoinExchange::processBitcoinExchange(void)
{
	std::string line;
	std::getline(m_file, line);
	while (std::getline(m_file, line))
	{
		size_t pos = line.find(CSV_DELIMITER);
		if (pos == std::string::npos)
		{
			_processLine(line, pos);
		}
		else
		{
			_printError("bad input => " + line);
		}
	}
}

void BitcoinExchange::_processLine(const std::string& line, size_t pos)
{
	std::string input;

	try
	{
		input = line.substr(0, pos);
		Date date = _parseDate(input);

		input = line.substr(pos + 3);
		BTC amount = _parseValue(input);

		Price price = _getPrice(date);
		std::cout << date << " => " << amount << " = " << price * amount << '\n';
	}
	catch(const std::exception& e)
	{
		_printError(std::string(e.what()) + " => " + input);
	}
}

Date BitcoinExchange::_parseDate(const std::string& date)
{
	int year, month, day;

	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
	{
		throw std::runtime_error("Invalid date format");
	}

	if (year < 0 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		throw std::runtime_error("Invalid date");
	}

	return date;
}

BTC BitcoinExchange::_parseValue(const std::string& value)
{
	float amount;

	if (sscanf(value.c_str(), "%f", &amount) != 1)
	{
		throw std::runtime_error("Invalid value format");
	}

	if (amount < 0)
	{
		throw std::runtime_error("Invalid value");
	}

	if (amount > 1000)
    {
        throw std::runtime_error("too large a number");
    }

	return amount;
}

Price BitcoinExchange::_getPrice(const Date& date)
{
	ExchangeRateDatabase::const_iterator it = m_database.lower_bound(date);

	if (it != m_database.begin())
	{
		--it;
	}

	return it->second;
}

void BitcoinExchange::_printError(const std::string& errorMsg)
{
	std::cout << "Error: " << errorMsg << std::endl;
}

/* ************************************************************************** */