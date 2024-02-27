/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilmar <gilmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:11:39 by gilmar            #+#    #+#             */
/*   Updated: 2024/02/12 10:10:44 by gilmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"

#include <iostream>

int main(void)
{
    try
    {
      // Test default constructor
      Array<int> arr1;
      std::cout << "arr1 size: " << arr1.size() << std::endl;

      // Test constructor with size parameter
      Array<int> arr2(5);
      std::cout << "arr2 size: " << arr2.size() << std::endl;

      // Test copy constructor and assignment operator
      Array<int> arr3 = arr2;
      Array<int> arr4;
      arr4 = arr2;

      // Atribuir valores aos elementos de arr3 e arr4 antes de imprimi-los
      for (unsigned int i = 0; i < arr3.size(); ++i)
      {
         arr3[i] = i;       // Atribuir valores sequenciais
         arr4[i] = i * 2;   // Atribuir valores sequenciais multiplicados por 2
      }
      
      // Modify arr2
      arr2[1] = 1;
      
      // Imprimir os elementos de arr2, arr3 e arr4
      for (unsigned int i = 0; i < arr2.size(); ++i)
      {
         std::cout << "arr2[" << i << "]: " << arr2[i] << ", arr3[" << i << "]: " << arr3[i] << ", arr4[" << i << "]: " << arr4[i] << std::endl;
      }

      // Test out-of-bounds access
      // Uncomment the line below to test the out-of-bounds exception
      // std::cout << arr2[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}