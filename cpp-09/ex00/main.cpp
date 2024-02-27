/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:30:37 by gilmar            #+#    #+#             */
/*   Updated: 2024/02/13 16:28:54 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc <filename>" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange::openInputFile(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        BitcoinExchange::loadDatabase();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    BitcoinExchange::processBitcoinExchange();

    return 0;
}
