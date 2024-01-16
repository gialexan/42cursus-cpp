/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:45:04 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 11:50:27 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstdlib>
# include <iostream>
# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <number>" << std::endl;
        return EXIT_FAILURE;
    }

    ScalarConverter::convert(argv[argc - 1]);

    return EXIT_SUCCESS;
}