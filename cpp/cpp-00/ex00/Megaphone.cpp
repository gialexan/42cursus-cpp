/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Magaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:02:20 by gialexan          #+#    #+#             */
/*   Updated: 2023/11/06 19:02:21 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1)
        std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        i = 1;
        while (i < argc)
        {
            j = 0;
            while (argv[i][j] != '\0')
                std::cout << (char)toupper(argv[i][j++]);
            if (i != argc - 1)
                std::cout << "";
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}
