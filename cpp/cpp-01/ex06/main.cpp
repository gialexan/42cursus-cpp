/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:06:00 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:54:26 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static std::string toUpperStr(std::string str);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
        return (1);
    }
    Harl harl;
    std::string level = toUpperStr(argv[1]); 
    harl.complain(level);
}

static std::string toUpperStr(std::string str)
{
    std::string::iterator it;
    std::string upperStr;
    for (it = str.begin(); it != str.end(); it++)
        upperStr += (char)std::toupper(*it);
    return (upperStr);
}