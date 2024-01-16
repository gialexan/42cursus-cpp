/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:56:26 by gilmar            #+#    #+#             */
/*   Updated: 2024/01/16 19:05:01 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.h"
#include <iostream>

int main(void)
{
    int var = MyMin<int>(10, 9);
    std::cout << var << std::endl;

    var = myMax<int>(10, 8);
    std::cout << var << std::endl;

    int a = 2;
    int b = 3;

    Swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
}
