/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:12:51 by gialexan          #+#    #+#             */
/*   Updated: 2023/12/09 20:47:12 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./ex04 <filename> <string_to_remove> <string_to_insert>" << std::endl;
        return (1);
    }

    FileReplacer("txt", "JOÃO", "WELTON");
}
