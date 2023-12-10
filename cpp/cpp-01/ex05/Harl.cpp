/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:03:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/10 09:28:27 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::_debug(void)
{
  std::cout
      << RED << "[DEBUG]\n" << YELLOW << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl << RESET;
}

void Harl::_info(void)
{
  std::cout
      << RED << "[INFO]\n" << YELLOW << "I cannot believe adding extra bacon cost more money. You "
         "didn't "
         "put enough bacon in my burger! If you did, I wouldn't be asking for "
         "more!"
      << std::endl << RESET;
}

void Harl::_warning(void)
{
  std::cout
      << RED << "[WARNING]\n" << YELLOW << "I think I deserve to have some extra bacon for free. I've "
         "been coming for years whereas you just started working here "
         "since last month."
      << std::endl << RESET;
}

void Harl::_error(void)
{
  std::cout
      << RED << "[ERROR]\n" << YELLOW << "This is unacceptable! I want to speak to the manager now."
      << std::endl << RESET;
}

void Harl::complain(std::string level)
{
    std::string levels[TOTAL_LEVEL] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functionPTR[TOTAL_LEVEL])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl:: _error};

    for (int i = 0; i < TOTAL_LEVEL; i++)
    {
      if (!levels[i].compare(level))
        (this->*functionPTR[i])();
    }
}