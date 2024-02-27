/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:56:26 by gilmar            #+#    #+#             */
/*   Updated: 2024/02/22 18:35:45 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.h"
#include <iostream>

int main(void)
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Iterating over integer array: ";
    Iter(intArray, intArrayLength, PrintElement<int>);
    std::cout << std::endl;

    // Test with an array of doubles
    // double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    // size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    // std::cout << "Iterating over double array: ";
    // Iter(doubleArray, doubleArrayLength, PrintElement<double>);
    // std::cout << std::endl;

    // Test with an array of doubles
    char doubleArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(char);

    std::cout << "Iterating over double array: ";
    Iter(doubleArray, doubleArrayLength, PrintElement<char>);
    std::cout << std::endl;
}
